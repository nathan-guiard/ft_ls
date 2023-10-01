/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 23:05:00 by nguiard           #+#    #+#             */
/*   Updated: 2023/10/01 16:57:31 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE
#define FT_TREE

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#include "libft.h"

#define NODE_MALLOC_SIZE 5

typedef struct content_cell
{
	struct stat	stat;
	char *		name;
}	content_cell;

typedef content_cell	content_type;
typedef struct tree *	node_type;
typedef node_type *		node_tab_type;

typedef struct tree
{
	content_type	content;
	node_tab_type	nodes;
	size_t			size;
}	tree;

typedef void			(*iter_tree_function)(tree);

//	new_tree.c
tree	new_tree(void);
tree	new_tree_content(content_type content);
tree	new_tree_nodes(node_tab_type nodes, size_t size);
tree	new_tree_content_nodes(content_type content, node_tab_type nodes, size_t size);

//	delete_tree.c
void	delete_node(tree node);
void	free_node_array(tree node);
void	delete_tree(tree node);

//	tree_manipulation.c
void	iter_tree(tree tr, iter_tree_function fnc);
void	iter_tree_reverse(tree tr, iter_tree_function fnc);

//	tree_nodes.c
void	add_node(tree *tr, node_type new);

//	tree_utils.c
size_t	nodelen(node_tab_type tab);

#endif