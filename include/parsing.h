/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:15:22 by nguiard           #+#    #+#             */
/*   Updated: 2023/07/08 19:20:45 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING
#define PARSING

#include <stdbool.h>

#include "libft.h"

typedef char *	str;

typedef struct parsing_info {
	bool	time;
	bool	flong;
	bool	all;
	bool	reverse;
	bool	recursive;
	str		*files;
}	parsing_info;

// parsing.c
parsing_info	parsing(int argc, str *argv);
parsing_info	default_settings();
void			parse_after_end_of_args(str *files, str *argv,
										int i, int nb_files);
char			parse_argument(parsing_info *infos, str	arg);

// ft_ls.h -> error.c
void	invalid_option_error(char s);

#endif