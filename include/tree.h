/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 23:05:00 by nguiard           #+#    #+#             */
/*   Updated: 2023/07/02 01:08:34 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE
#define FT_TREE

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define NODE_MALLOC_SIZE 5

typedef void *			content_type;
typedef struct tree *	node_type;
typedef node_type *		node_tab_type;
typedef void			(*iter_tree_function)(content_type);
typedef content_type	(*map_tree_function)(content_type);

typedef struct tree
{
	content_type	content;
	node_tab_type	nodes;
	size_t			size;
}	tree;

//	new_tree.c
tree	new_tree(void);
tree	new_tree_content(content_type content);
tree	new_tree_nodes(node_tab_type nodes, size_t size);
tree	new_tree_content_nodes(content_type content, node_tab_type nodes, size_t size);

//	tree_manipulation.c
void	iter_tree(tree tr, iter_tree_function fnc);
void	iter_tree_reverse(tree tr, iter_tree_function fnc);

//	tree_nodes.c
void	add_node(tree *tr, node_type new);

//	tree_utils.c
size_t	nodelen(node_tab_type tab);

#endif