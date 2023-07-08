/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:02:42 by nguiard           #+#    #+#             */
/*   Updated: 2023/07/08 19:21:33 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	invalid_option_error(char s) {
	ft_putstr_fd("ft_ls: invalid option -- \'", 2);
	ft_putchar_fd(s, 2);
	ft_putendl_fd("\'", 2);
}