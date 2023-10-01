/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:12:44 by nguiard           #+#    #+#             */
/*   Updated: 2023/10/01 15:54:37 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	dirlen(str path);
static void	add_directory_recursive(dirent *curr_file, str directory,
							parsing_info info, tree *ptr, tree *res);

void print(tree c) {
	if (!c.nodes) {
		return;
	}

	printf("%s: ", c.content.name);

	for (int i = 0; c.nodes[i]; i++) {
		printf("%s ", c.nodes[i]->content.name);
	}
	printf("\n");
}

tree get_files(str directory, parsing_info info) {
	tree			res = new_tree();
	DIR 			*d = opendir(directory);
	dirent			*curr_file;
	int				dir_size = dirlen(directory);
	content_type	curr_content;
	stat_t			curr_stat;

	stat(directory, &curr_stat);
	res.content.name = strdup(directory);
	res.content.stat = curr_stat;

	if (!d) {
		printf("No %s\n", directory);
		return res;
	}
	curr_file = readdir(d);
	ft_printf("Dir \033[32m%s\033[0m [%d]\n", directory ,dir_size);
	while (curr_file) {
		lstat(curr_file->d_name, &curr_stat);
		tree *ptr = ft_calloc(sizeof(tree), 1);
		bool recursive_dir = curr_file->d_type == TDIR && info.recursive;
		bool is_not_curr_dir = ft_strcmp(".", curr_file->d_name) &&
			ft_strcmp("..", curr_file->d_name);
		
		if (is_not_curr_dir && recursive_dir) {
			add_directory_recursive(curr_file, directory, info, ptr, &res);
		} else {
			curr_content.name = ft_strdup(curr_file->d_name);
			curr_content.stat = curr_stat;
			*ptr = new_tree_content(curr_content);
			add_node(&res, ptr);
		}
		curr_file = readdir(d);
	}
	closedir(d);

	return res;
}

static void	add_directory_recursive(dirent *curr_file, str directory,
							parsing_info info, tree *ptr, tree *res) {
	content_type	new_content;
	str	new_name = ft_calloc(ft_strlen(directory) + ft_strlen(curr_file->d_name) + 2, 1);

	if (ft_strcmp(".", directory)) {
		strcat(new_name, directory);
		new_name[ft_strlen(directory)] = '/';
		strcat(new_name, curr_file->d_name);
	} else {
		strcpy(new_name, curr_file->d_name);
	}

	*ptr = get_files(new_name, info);
	new_content.stat = ptr->content.stat;
	new_content.name = ptr->content.name;
	*ptr = new_tree_content_nodes(new_content, ptr->nodes, ptr->size);
	free(new_name);
	add_node(res, ptr);
}

static int dirlen(str path) {
	DIR		*d = opendir(path);
	dirent	*f;
	int		res = 0;

	if (!d) {
		return 0;
	}
	f = readdir(d);
	while (f)
	{
		res++;
		f = readdir(d);
	}
	closedir(d);
	return res;
}