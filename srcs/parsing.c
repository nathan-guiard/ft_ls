/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:24:28 by nguiard           #+#    #+#             */
/*   Updated: 2023/07/08 19:26:20 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

parsing_info	parsing(int argc, str *argv) {
	parsing_info infos = default_settings();
	int nb_files = 0;

	if (!argv || !argv[0] || !argv[1] || argc == 1)
		return infos;

	infos.files = ft_calloc(sizeof(str), argc);

	for (int i = 1; argv[i]; i++) {
		str	arg = argv[i];
		if (arg[0] == '-') {
			if (arg[1] == '-') {
				parse_after_end_of_args(infos.files, argv, i + 1, nb_files);
				break;
			}
			char c = parse_argument(&infos, arg);
			if (c) {
				invalid_option_error(c);
				exit(2);
			}
		} else {
			infos.files[nb_files] = arg;
			nb_files++;
		}
	}
	
	return infos;
}

parsing_info	default_settings() {
	parsing_info 	base_settings;
	
	base_settings.all = false;
	base_settings.files = 0;
	base_settings.flong = false;
	base_settings.recursive = false;
	base_settings.reverse = false;
	base_settings.time = false;

	return base_settings;
}


// This function assumes that arg[0] == '-'
char	parse_argument(parsing_info *infos, str	arg) {
	for (int i = 1; arg[i]; i++) {
		if (arg[i] == 'a')
			infos->all = true;
		else if (arg[i] == 'l')
			infos->flong = true;
		else if (arg[i] == 'r')
			infos->reverse = true;
		else if (arg[i] == 'R')
			infos->recursive = true;
		else if (arg[i] == 't')
			infos->time = true;
		else
			return arg[i];
	}
	return 0;
}

void	parse_after_end_of_args(str *files, str *argv, int i, int nb_files) {
	for (; argv[i]; i++) {
		files[nb_files] = argv[i];
		nb_files++;
	}
}