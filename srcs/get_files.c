/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:12:44 by nguiard           #+#    #+#             */
/*   Updated: 2023/09/11 18:44:14 by nguiard          ###   ########.fr       */
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

	if (info.recursive) {
		ft_putendl_fd("Recursive not supported yet", 2);
		exit(1);
	}

	curr_file = readdir(d);
	ft_printf("Dir len: %d\n", dir_size);
	while (curr_file) {
		stat(curr_file->d_name, &curr_stat);
		if (curr_file->d_name) {			
			curr_content.name = ft_strdup(curr_file->d_name);
			curr_content.stat = curr_stat;
			tree *ptr = ft_calloc(sizeof(tree), 1);
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