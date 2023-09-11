/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:44:36 by nguiard           #+#    #+#             */
/*   Updated: 2023/09/11 18:47:52 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

/**
 * @brief		Frees the content of a node. Does not free the
 * 				array of nodes. Make sure that the array is empty
 * 
 * @param node	tree node
 */
void	delete_node(tree node) {
	if (node.content.name) {
		free(node.content.name);
	}
	if (node.nodes) {
		free(node.nodes);
	}
}

void	free_node_array(tree node) {
	if (node.nodes) {
		for (size_t i = 0; i < node.size; i++) {
			if (node.nodes[i]) {
				free(node.nodes[i]);
			}
		}
	}
}

void	delete_tree(tree root) {
	if (root.nodes) {
		for (size_t i = nodelen(root.nodes); i + 1 != 0; i--) {
			if (root.nodes[i]) {
				delete_tree(*root.nodes[i]);
			}
		}
	}
	
	free_node_array(root);
	delete_node(root);
}