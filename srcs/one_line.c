/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:01:32 by nathan            #+#    #+#             */
/*   Updated: 2023/09/30 16:08:39 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

str mode_str(mode_t mode) {
	str	perm = ft_calloc(12, 1);
	ft_memset(perm, '-', 10);

	if (S_ISDIR(mode))			perm[0] = 'd';
    else if (S_ISLNK(mode)) 	perm[0] = 'l';
    else if (S_ISCHR(mode))		perm[0] = 'c';
    else if (S_ISBLK(mode))		perm[0] = 'b';
    else if (S_ISSOCK(mode))	perm[0] = 's';
    else if (S_ISFIFO(mode))	perm[0] = 'p';

    if (mode & S_IRUSR) perm[1] = 'r';
    if (mode & S_IWUSR) perm[2] = 'w';
    if (mode & S_IXUSR) perm[3] = 'x';
    if (mode & S_IRGRP) perm[4] = 'r';
    if (mode & S_IWGRP) perm[5] = 'w';
    if (mode & S_IXGRP) perm[6] = 'x';
    if (mode & S_IROTH) perm[7] = 'r';
    if (mode & S_IWOTH) perm[8] = 'w';
    if (mode & S_IXOTH) perm[9] = 'x';

	perm[10] = ' ';
	return perm;
}

int number_size(size_t nb) {
	int ret = 1;

	while (nb > 10) {
		nb /= 10;
		ret++;
	}
	return ret;
}

str size_str(int size, size_t max) {
	int size_max = number_size(max);
	int size_nb = number_size(size);
	str line = ft_calloc(size_max + 3, 1);
	str size_str = ft_itoa(size);

	ft_memset(line, ' ', size_max + 2);
	ft_strlcpy(line + 1 + (size_max - size_nb), size_str, strlen(size_str) + 1);
	line[1 + size_max] = ' ';
	free(size_str);

	return line;
}

str	long_stat(stat_t file, size_t max) {
	str line = ft_calloc(4096, 1);
	str mode = mode_str(file.st_mode);
	str nlink = ft_itoa(file.st_nlink);
	str size = size_str(file.st_size, max);
	str date = ctime(&file.st_mtime) + 4;
	date[12] = 0;

	strcat(line, mode);
	strcat(line, nlink);
	strcat(line, " ");
	strcat(line, getpwuid(file.st_uid)->pw_name);
	strcat(line, " ");
	strcat(line, getgrgid(file.st_gid)->gr_name);
	strcat(line, size);
	strcat(line, date);
	strcat(line, " ");

	free(mode);
	free(nlink);
	free(size);

	return line;
};

str	link_info(content_type file) {
	str	res = 0;
	int size = 0;
	char buff[4096] = {0};

	size = readlink(file.name, buff, 4096);
	buff[size] = 0;

	res = ft_calloc(strlen(buff) + 5, 1);
	strcpy(res, " -> ");
	strcat(res, buff);

	return res;
}

void	display_one_line(content_type file, parsing_info info, size_t max_size) {
	char	line[10000];
	str		long_line = 0;

	ft_bzero(line, 10000);

	if (info.flong) {
		long_line = long_stat(file.stat, max_size);
		strcat(line, long_line);
		free(long_line);
	}
	strcat(line, file.name);
	if (info.flong && S_ISLNK(file.stat.st_mode)) {
		long_line = link_info(file);
		strcat(line, long_line);
		free(long_line);
	}

	ft_putendl_fd(line, 1);
}