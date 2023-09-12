/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:37:48 by nguiard           #+#    #+#             */
/*   Updated: 2023/09/12 19:06:45 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t	index_of_first_alnum(str s) {
	size_t i = 0;

	for (; s[i]; i++) {
		if (ft_isalnum(s[i])) {
			break;
		}
	}
	
	return i;
}

bool	ft_strcasecmp(str s1, str s2) {
	size_t	i = 0;
	for (; s1[i] && s2[i]; i++) {
		if (ft_tolower(s1[i]) != ft_tolower(s2[i])) {
			printf("%s %s: %c != %c\n", s1, s2, s1[i], s2[i]);
			return s1[i] > s2[i];
		}
	}
	
	if (s1[i]  == s2[i]) {
		if (ft_strcmp(s1, s2) < 0) {
			return true;
		}
		return false;
	}
	printf("whole shit was the same\n");
	return s1[i] > s2[i];
}

bool	display_cmp(content_type c1, content_type c2, parsing_info info) {
	int	off1, off2;

	// if (info.time) {
	// 	return (c1.stat.st_ctime < c2.stat.st_ctime) ^ info.reverse;
	// }
	off1 = index_of_first_alnum(c1.name);
	off2 = index_of_first_alnum(c2.name);

	printf("\033[34mComparaison avec\n%s\n%s\n\033[0m", c1.name + off1, c2.name + off2);
	
	return ft_strcasecmp(c1.name + off1, c2.name + off2) ^ info.reverse;
}

void	swap_nodes(node_type *a, node_type *b) {
	node_type tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	display(tree tr, parsing_info info) {
	for (int i = 0; tr.nodes[i]; i++) {
		for (int j = 0; tr.nodes[j + 1]; j++) {
			if (display_cmp(tr.nodes[j]->content, tr.nodes[j + 1]->content, info)) {
				swap_nodes(&tr.nodes[j], &tr.nodes[j + 1]);
			}
		}
		for (int k = 0; tr.nodes[k]; k++) {
			printf("%s ", tr.nodes[k]->content.name);
		}
		printf("\n");
	}

	for (int i = 0; tr.nodes[i]; i++) {
		printf("%s\n", tr.nodes[i]->content.name);
	}
}