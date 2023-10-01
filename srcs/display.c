/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:37:48 by nguiard           #+#    #+#             */
/*   Updated: 2023/10/01 17:13:13 by nathan           ###   ########.fr       */
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
	if (!tr || !tr->nodes) {
		return;
	}
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

	if (!tr->nodes) {
		return max;
	}

	for (int i = 0; tr->nodes[i]; i++) {
		if ((unsigned long)tr->nodes[i]->content.stat.st_size > max)
			max = tr->nodes[i]->content.stat.st_size;
	}
	
	return max;
}

str basename(const str path) {
    char *last_slash = strrchr(path, '/');

    if (last_slash != NULL) {
        return strdup(last_slash + 1);
    } else {
        return strdup(path);
    }
}


void	display(tree tr, parsing_info info, bool first, str root) {
	size_t			max_size = get_max_size(&tr);
	node_tab_type	next_nodes = ft_calloc(sizeof(node_type), tr.size + 1);
	int				k = 0;

	(void)root;

	if (!tr.nodes) {
		free(next_nodes);
		if (first) {
			display_one_line(tr.content, info, tr.content.stat.st_size);
		}
		return;
	}

	sort_tree(&tr, info);

	if (!first)
		ft_putchar_fd('\n', 1);
	if (info.flong)
		ft_printf("%s:\n", tr.content.name);
	for (int i = 0; tr.nodes[i]; i++) {
		content_type	c = tr.nodes[i]->content;
		str				dir_name = basename(c.name);

		if (!(dir_name[0] == '.' && !info.all)) {
			display_one_line(c, info, max_size);
		}
		free(dir_name);
		if (S_ISDIR(c.stat.st_mode)) {
			next_nodes[k] = tr.nodes[i];
			k++;
		}
	}

	for (int i = 0; next_nodes[i]; i++) {
		display(*next_nodes[i], info, false, root);
	}
	
	free(next_nodes);
}