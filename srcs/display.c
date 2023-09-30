/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:37:48 by nguiard           #+#    #+#             */
/*   Updated: 2023/09/30 15:25:36 by nathan           ###   ########.fr       */
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

void	swap_nodes(node_type *a, node_type *b) {
	node_type tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_strcasecmp(str s1, str s2) {
	size_t	i = 0;
	for (; s1[i] && s2[i]; i++) {
		char a = ft_tolower(s1[i]);
		char b = ft_tolower(s2[i]);

		if (a != b) {
			return a - b;
		}
	}
	return s1[i] > s2[i];
}

bool	display_cmp(content_type c1, content_type c2, bool sort_time) {
	int	off1, off2;
	int ret_offset, ret_normal;


	if (sort_time) {
		return (c1.stat.st_ctime < c2.stat.st_ctime);
	}
	off1 = index_of_first_alnum(c1.name);
	off2 = index_of_first_alnum(c2.name);

	if (!c1.name[off1] || !c2.name[off2]) {
		return 0;
	}

	ret_offset = ft_strcasecmp(c1.name + off1, c2.name + off2);

	if (ret_offset != 0) {
		return (ret_offset > 0);
	}
	ret_normal = ft_strcmp(c1.name, c2.name);
	return (ret_normal > 0);
}

void	sort_tree(tree *tr, parsing_info info) {
	for (int i = 0; tr->nodes[i]; i++) {
		for (int j = 0; tr->nodes[j + 1]; j++) {
			if (display_cmp(tr->nodes[j]->content, tr->nodes[j + 1]->content, info.time) ^ info.reverse) {
				swap_nodes(&tr->nodes[j], &tr->nodes[j + 1]);
			}
		}
	}
}

size_t get_max_size(tree *tr) {
	size_t	max = 0;

	for (int i = 0; tr->nodes[i]; i++) {
		if ((unsigned long)tr->nodes[i]->content.stat.st_size > max)
			max = tr->nodes[i]->content.stat.st_size;
	}
	
	return max;
}

void	display(tree tr, parsing_info info, bool first) {
	size_t max_size = get_max_size(&tr);
	sort_tree(&tr, info);
	
	if (!first) {
		ft_printf("%s:\n", tr.content.name);
	}
	for (int i = 0; tr.nodes[i]; i++) {
		content_type c = tr.nodes[i]->content;
		if (!(c.name[0] == '.' && !info.all)) {
			display_one_line(c, info, max_size);
		}
	}
	if (!first) {
		ft_putchar_fd(20, 1);
	}
}