/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:55:10 by nguiard           #+#    #+#             */
/*   Updated: 2023/07/08 18:07:03 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void m(content_type k) {
	puts(k);
}

int main () {
	tree t;
	node_tab_type	tab = calloc(sizeof(node_type), 3);
	tree a = new_tree_content(strdup("salut"));
	tree b = new_tree_content(strdup("truc"));
	
	t = new_tree();
	t.content = strdup("yayaya");
	tab[0] = &a;
	tab[1] = &b;
	t.nodes = tab;
	
	iter_tree_reverse(t, m);

	delete_tree(t);
	return 0;
}