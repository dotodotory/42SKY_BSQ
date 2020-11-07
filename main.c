/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiykim <jiykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:29:08 by jiykim            #+#    #+#             */
/*   Updated: 2020/11/07 14:56:55 by jiykim           ###   ########.fr       */
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
	g_ret[0] = 0;
	g_ret[1] = 0;
	g_ret[2] = 0;
	g_m_i[0] = 1;
	g_m_i[1] = 1;
}

void	prc_stdin(char *buff, int prc_f)
{
	int i;
	int **map;

	i = -1;
	map = (int **)malloc(sizeof(int *) * g_row + 2);
	while (++i < g_row + 1)
		map[i] = ft_calloc(map[i], g_col + 1);
	map[i] = 0;
	prc_f = ft_read_file(0, buff);
	if (!is_error(prc_f))
		return ;
	prc_f = ft_read_file2(map, 0, buff);
	if (prc_f == -1)
		ft_free_map(map);
	if (!is_error(prc_f))
		return ;
	chk(map);
	print_map(map, g_c);
	ft_free_map(map);
}

int		main(int argc, char **argv)
{
	int		main_f;
	char	buff[BUFF_SIZE];
	int		idx;

	main_f = 0;
	if (argc == 1)
		prc_stdin(buff, main_f);
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
