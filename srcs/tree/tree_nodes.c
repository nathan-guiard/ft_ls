/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 00:21:32 by nguiard           #+#    #+#             */
/*   Updated: 2023/09/11 18:42:30 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

size_t	nodes_len(tree tr) {
	size_t size = 0;

	if (!tr.nodes) {
		return 0;
	}

	for (int i = 0; tr.nodes[i]; i++) {
		size++;
	}

	return size;
}

void	add_node(tree *tr, node_type new) {
	size_t size;

	if (!tr)
		return;
	size = nodes_len(*tr);

	if (!tr->nodes) {
		tr->nodes = calloc(sizeof(tree), NODE_MALLOC_SIZE);
		tr->nodes[0] = new;
		tr->size = NODE_MALLOC_SIZE;
	} else if (size >= tr->size) {
		node_tab_type	new_tab = calloc(sizeof(tree), size + NODE_MALLOC_SIZE);
		
		memcpy(new_tab, tr->nodes, size * sizeof(tree));
		free(tr->nodes);
		tr->nodes = new_tab;
		tr->nodes[size] = new;
		tr->size = size + NODE_MALLOC_SIZE;
	}
	else
		tr->nodes[size] = new;
}