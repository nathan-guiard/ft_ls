/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:12:44 by nguiard           #+#    #+#             */
/*   Updated: 2023/09/11 20:36:21 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int dirlen(str path);

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
		stat(curr_file->d_name, &curr_stat);
		tree *ptr = ft_calloc(sizeof(tree), 1);
		if (curr_file->d_type == 4 && info.recursive &&
			strcmp(".", curr_file->d_name) &&
			strcmp("..", curr_file->d_name)) {

			str	new_name = ft_calloc(ft_strlen(directory) + ft_strlen(curr_file->d_name) + 2, 1);
			strcat(new_name, directory);
			new_name[ft_strlen(directory)] = '/';
			strcat(new_name, curr_file->d_name);
			*ptr = get_files(new_name, info);
			free(new_name);
			add_node(&res, ptr);
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