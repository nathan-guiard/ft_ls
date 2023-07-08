/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:55:10 by nguiard           #+#    #+#             */
/*   Updated: 2023/07/08 19:25:23 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void m(content_type k) {
	puts(k);
}

int main (int argc, str *argv) {
	parsing_info p_info = parsing(argc, argv);

	printf("-a: %s\n", p_info.all ? "true": "false");
	printf("-l: %s\n", p_info.flong ? "true": "false");
	printf("-r: %s\n", p_info.reverse ? "true": "false");
	printf("-R: %s\n", p_info.recursive ? "true": "false");
	printf("-t: %s\n", p_info.time ? "true": "false");
	printf("Files:\n");
	
	if (!p_info.files) {
		printf("\tNone\n");
	}
	else {
		for (int i = 0; p_info.files[i]; i++) {
			printf("\t%s\n", p_info.files[i]);
		}
		free(p_info.files);
	}
	return 0;
}