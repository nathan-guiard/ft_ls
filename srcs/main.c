/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:55:10 by nguiard           #+#    #+#             */
/*   Updated: 2023/10/01 17:12:48 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool	display_cmp(content_type c1, content_type c2, parsing_info info);

int main (int argc, str *argv) {
	parsing_info	p_info = parsing(argc, argv);
	tree			files;

	if (p_info.files == 0) {
		p_info.files = ft_calloc(sizeof(str), 2);
		p_info.files[0] = ".";
	}

	for (int i = 0; p_info.files[i]; i++) {
		files = get_files(p_info.files[i], p_info);
		display(files, p_info, !i, p_info.files[i]);	
		delete_tree(files);
	}

	if (p_info.files) {
		free(p_info.files);
	}

	return 0;
}