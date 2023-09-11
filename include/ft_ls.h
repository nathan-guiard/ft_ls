/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:55:07 by nguiard           #+#    #+#             */
/*   Updated: 2023/09/11 20:32:40 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
#define FT_LS

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <error.h>
#include <dirent.h>

#include "tree.h"
#include "libft.h"
#include "parsing.h"

#define GET(x, y) x ? x : y
#define TDIR 4

typedef struct stat stat_t;
typedef struct dirent dirent;

//	error.c
void	invalid_option_error(char s);

// get_files.c
tree	get_files(str directory, parsing_info info);

// display.c
void	display(tree tr, parsing_info info);

#endif