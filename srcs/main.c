/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:55:10 by nguiard           #+#    #+#             */
/*   Updated: 2023/07/02 01:11:38 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void m(content_type k) {
	puts(k);
}

int main () {
	tree t;
	node_tab_type	tab = malloc(sizeof(tree *) * 2);
	tree a = new_tree_content("salut");
	tree b = new_tree_content("truc");
	
	t = new_tree();
	t.content = "hello";
	tab[0] = &a;
	tab[1] = &b;
	t.nodes = tab;
	
	iter_tree_reverse(t, m);

	for (int i = 0; i < 20; i++) {
		tree b;

		b = new_tree_content("b");
		add_node(&t, &b);
		iter_tree_reverse(t, m);
	}
	return 0;
}