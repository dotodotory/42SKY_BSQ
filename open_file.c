/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiykim <jiykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:44:23 by jiykim            #+#    #+#             */
/*   Updated: 2020/11/05 00:42:10 by jiykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_open_file(char *file, char *buf)
{
	int open_f;
	int fd;

	if (0 < (fd = open(file, O_RDONLY)))
	{
		open_f = ft_read_file(fd, buf);
		close(fd);
	}
	else
		return (0);
	return (open_f);
}

int	ft_open_file2(char *file2, char *buf2)
{
	int open_f2;
	int i;
	int **map;
	int fd2;

	i = -1;
	map = (int **)malloc(sizeof(int *) * g_row + 2);
	while (++i < g_row + 1)
		map[i] = ft_calloc(map[i], g_col + 1);
	map[i] = 0;
	if (0 < (fd2 = open(file2, O_RDONLY)))
	{
		open_f2 = ft_read_file2(map, fd2, buf2);
		if (open_f2 == -1)
		{
			ft_free_map(map);
			return (-1);
		}
	}
	else
		return (0);
	chk(map);
	print_map(map, g_c);
	ft_free_map(map);
	return (1);
}
