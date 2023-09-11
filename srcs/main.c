/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:55:10 by nguiard           #+#    #+#             */
/*   Updated: 2023/09/11 19:36:51 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main (int argc, str *argv) {
	parsing_info	p_info = parsing(argc, argv);
	tree			files;
	
	files = get_files(".", p_info);
	display(files, p_info);

	delete_tree(files);
	if (p_info.files) {
		free(p_info.files);
	}
	return 0;
}