/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiykim <jiykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:29:08 by jiykim            #+#    #+#             */
/*   Updated: 2020/11/05 00:11:19 by jiykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_free_map(int **ptr)
{
	int ptr_i;

	ptr_i = 0;
	while (ptr_i < g_row + 1)
		free(ptr[ptr_i++]);
	free(ptr);
}

void	init_gvar(void)
{
	g_row = 0;
	g_col = 0;
	g_f.flag = 0;
	g_f2.flag = 0;
	g_col_size = 0;
	g_cnt = 0;
	ret[0] = 0;
	ret[1] = 0;
	ret[2] = 0;
}

int		main(int argc, char **argv)
{
	int		main_f;
	char	buff[BUFF_SIZE];
	int		idx;
	int		in_size;
	char	map_name[50];

	if (argc == 1)
	{
		in_size = read(0, buff, sizeof(buff));
		idx = -1;
		while (buff[++idx] != '\n')
			map_name[idx] = buff[idx];
		map_name[idx] = '\0';
		main_f = ft_open_file(map_name, buff);
		if (!is_error(main_f))
			return (0);
		main_f = ft_open_file2(map_name, buff);
		if (!is_error(main_fV))
			return (0);
	}
	idx = 0;
	while (++idx < argc)
	{
		init_gvar();
		main_f = ft_open_file(argv[idx], buff);
		if (!is_error(main_f))
			continue ;
		main_f = ft_open_file2(argv[idx], buff);
		if (!is_error(main_f))
			continue ;
	}
	return (0);
}
