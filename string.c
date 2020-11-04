/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiykim <jiykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:29:00 by jiykim            #+#    #+#             */
/*   Updated: 2020/11/05 00:38:22 by jiykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strncpy(char *dest, char *src, int size)
{
	int index;

	index = 0;
	while (index < size)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int		*ft_calloc(int *addr, int size)
{
	int i;

	addr = (int*)malloc(sizeof(int) * (size + 1));
	i = 0;
	while (i < size)
		addr[i++] = 0;
	addr[i] = -1;
	return (addr);
}
