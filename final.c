/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiykim <jiykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:31:13 by jiykim            #+#    #+#             */
/*   Updated: 2020/11/05 00:40:31 by jiykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		minimum(int i, int j, int **map)
{
	int min;

	min = (map[i - 1][j] > map[i][j - 1] ? map[i][j - 1] : map[i - 1][j]);
	min = (min > map[i - 1][j - 1] ? map[i - 1][j - 1] : min);
	return (min);
}

void	chk(int **map)
{
	int i;
	int j;

	i = 1;
	while (map[i] != 0)
	{
		j = 1;
		while (map[i][j] != -1)
		{
			if (map[i][j] != 0)
			{
				map[i][j] = minimum(i, j, map) + 1;
				if (map[i][j] > g_ret[0])
				{
					g_ret[0] = map[i][j];
					g_ret[1] = i;
					g_ret[2] = j;
				}
			}
			j++;
		}
		i++;
	}
}

void	print_map(int **map, char *moji)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (map[i] != 0)
	{
		j = 1;
		while (map[i][j] != -1)
		{
			if (i >= g_ret[1] - g_ret[0] + 1 && i <= g_ret[1] &&
				j >= g_ret[2] - g_ret[0] + 1 && j <= g_ret[2])
				write(1, &moji[2], 1);
			else if (map[i][j] == 0)
				write(1, &moji[1], 1);
			else
				write(1, &moji[0], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
