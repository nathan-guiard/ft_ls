/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:55:10 by nguiard           #+#    #+#             */
/*   Updated: 2023/09/11 18:50:14 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main (int argc, str *argv) {
	parsing_info	p_info = parsing(argc, argv);
	tree			files;
	
	files = get_files(".", p_info);

	for (size_t i = 0; files.nodes[i]; i++) {
		ft_printf("%d: %s\n", i, files.nodes[i]->content.name);
	}

	delete_tree(files);
	return 0;
}