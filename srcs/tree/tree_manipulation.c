/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 23:23:25 by nguiard           #+#    #+#             */
/*   Updated: 2023/07/02 00:13:08 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

int a = 0;

void	iter_tree(tree tr, iter_tree_function fnc) {
	fnc(tr.content);

	if (tr.nodes) {
		for (size_t i = 0; tr.nodes[i]; i++) {
			iter_tree(*tr.nodes[i], fnc);
		}
	}
}

void	iter_tree_reverse(tree tr, iter_tree_function fnc) {

	if (tr.nodes) {
		for (size_t i = nodelen(tr.nodes) ; i + 1 != 0; i--) {
			if (tr.nodes[i]) {
				iter_tree(*tr.nodes[i], fnc);
			}
		}
	}
	
	fnc(tr.content);
}