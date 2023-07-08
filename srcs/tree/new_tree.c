/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 23:08:48 by nguiard           #+#    #+#             */
/*   Updated: 2023/07/03 20:44:33 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

tree	new_tree(void) {
	tree	res;

	res.content = NULL;
	res.nodes = NULL;
	res.size = 0;

	return res;
}

tree	new_tree_content(content_type content) {
	tree	res;
	
	res.content = content;
	res.nodes = NULL;
	res.size = 0;

	return res;
}

tree	new_tree_nodes(node_tab_type nodes, size_t size) {
	tree	res;
	
	res.content = NULL;
	res.nodes = nodes;
	res.size = size;

	return res;
}

tree	new_tree_content_nodes(content_type content,
								node_tab_type nodes,
								size_t size) {
	tree	res;
	
	res.content = content;
	res.nodes = nodes;
	res.size = size;

	return res;
}





