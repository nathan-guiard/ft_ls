/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:37:48 by nguiard           #+#    #+#             */
/*   Updated: 2023/09/11 20:38:33 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t	index_of_first_alnum(str s) {
	size_t i = 0;

	for (; s[i]; i++) {
		if (ft_isalnum(s[i])) {
			i++;
			break;
		}
	}
	
	return i;
}

bool	ft_strcasecmp(str s1, str s2) {
	size_t	i = 0;
	for (; s1[i] && s2[i]; i++) {
		if (ft_tolower(s1[i]) != ft_tolower(s2[i])) {
			return s1[i] > s2[i];
		}
	}
	
	return s1[i] > s2[i];
}

bool	display_cmp(content_type c1, content_type c2, parsing_info info) {
	int	off1, off2;

	if (info.time) {
		return (c1.stat.st_ctime > c2.stat.st_ctime) ^ info.reverse;
	}
	off1 = index_of_first_alnum(c1.name);
	off2 = index_of_first_alnum(c2.name);
	
	return ft_strcasecmp(c1.name + off1, c2.name + off2) ^ info.reverse;
}

void	display(tree tr, parsing_info info) {
	(void)tr;
	(void)info;
}