/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiykim <jiykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:45:37 by jiykim            #+#    #+#             */
/*   Updated: 2020/11/05 00:15:44 by jiykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_atoi(char *str, int size)
{
	int a_i;

	a_i = 0;
	while (str[a_i] == ' ' || (str[a_i] >= 9 && str[a_i] <= 13))
		a_i++;
	while (a_i < size)
	{
		if (!(str[a_i] >= '0' && str[a_i] <= '9'))
			return (0);
		g_row = g_row * 10 + (str[a_i] - '0');
		a_i++;
	}
	return (1);
}

int		ft_first_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (!(ft_atoi(str, i - 3)))
	{
		free(str);
		return (0);
	}
	g_c[0] = str[i - 3];
	g_c[1] = str[i - 2];
	g_c[2] = str[i - 1];
	if (g_c[0] == g_c[1] || g_c[1] == g_c[2] || g_c[2] == g_c[0])
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}

int		ft_read_file(int fd, char *buf)
{
	char *temp;

	while ((g_f.rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		g_f.buf_i = 0;
		while (g_f.flag == 0 && buf[g_f.buf_i] != '\n')
			g_f.buf_i++;
		if (g_f.flag++ == 0)
		{
			temp = (char*)malloc(sizeof(char) * (g_f.buf_i + 1));
			if (!ft_first_line(ft_strncpy(temp, buf, g_f.buf_i)))
				return (0);
		}
		while (g_f.buf_i < g_f.rd)
		{
			if (buf[g_f.buf_i++] == '\n')
			{
				g_col = g_col_size;
				g_col_size = -1;
				g_cnt++;
			}
			g_col_size++;
		}
	}
	return (g_cnt != g_row + 1 ? -1 : 1);
}
