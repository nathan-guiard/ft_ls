/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 00:21:32 by nguiard           #+#    #+#             */
/*   Updated: 2023/09/05 21:32:39 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	add_node(tree *tr, node_type new) {
	size_t size = tr->size;

	if (!tr->nodes) {
		tr->nodes = calloc(sizeof(tree), NODE_MALLOC_SIZE);
		tr->nodes[0] = new;
		tr->size = NODE_MALLOC_SIZE;
	} else if (size == tr->size) {
		node_tab_type	new_tab = calloc(sizeof(tree), size + NODE_MALLOC_SIZE);
		
		memcpy(new_tab, tr->nodes, size * sizeof(tree));
		tr->nodes = new_tab;
		tr->nodes[size] = new;
		tr->size = size + NODE_MALLOC_SIZE;
	} else {
		tr->nodes[size] = new;
	}
}