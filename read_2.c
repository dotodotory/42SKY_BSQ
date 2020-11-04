/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiykim <jiykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:48:00 by jiykim            #+#    #+#             */
/*   Updated: 2020/11/05 00:24:51 by jiykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_in_str(char buf_c)
{
	if (buf_c == g_c[0])
		return (1);
	if (buf_c == g_c[1])
		return (0);
	return (-1);
}

int	ft_read_file2(int **map, int fd2, char buf2[])
{
	while (0 < (g_f2.rd = read(fd2, buf2, BUFF_SIZE)))
	{
		g_f2.buf_i = -1;
		while (++g_f2.buf_i < g_f2.rd)
		{
			while (g_f2.flag == 0 && buf2[g_f2.buf_i] != '\n')
				g_f2.buf_i++;
			if (g_f2.flag++ == 0)
				g_f2.buf_i++;
			if (buf2[g_f2.buf_i] == '\n')
			{
				if (g_m_i[1] - 1 != g_col)
					return (-1);
				map[g_m_i[0]++][g_m_i[1]] = -1;
				g_m_i[1] = 1;
			}
			else if ((map[g_m_i[0]][g_m_i[1]++] =
					is_in_str(buf2[g_f2.buf_i])) == -1)
				return (-1);
		}
	}
	return (1);
}
