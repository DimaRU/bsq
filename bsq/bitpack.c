/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitpack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssantiag <ssantiag@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:18:57 by ssantiag          #+#    #+#             */
/*   Updated: 2021/02/10 20:18:57 by ssantiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft_tools.h"

bool	bitpack(t_map map, char *line, int row)
{
	int		col;
	long	off;

	col = -1;
	while (++col < map.cols)
	{
		off = row * map.cols + col;
		if (*line == map.obstacle)
			map.map[off >> 3] |= 1 << (off & 0x7);
		else if (*line == map.empty)
			map.map[off >> 3] &= ~(1 << (off & 0x7));
		else
			return (false);
		line++;
	}
	return (*line == '\n');
}

void	bitunpack(t_map map, char *line, int row)
{
	int		col;
	long	off;

	col = -1;
	while (++col < map.cols)
	{
		off = row * map.cols + col;
		*line++ = map.map[off >> 3] & 1 << (off & 0x7) ?
			map.obstacle : map.empty;
	}
	*line = '\n';
}
