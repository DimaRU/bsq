/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssantiag <ssantiag@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:17:46 by ssantiag          #+#    #+#             */
/*   Updated: 2021/02/08 11:17:46 by ssantiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft_tools.h"
#include <stdlib.h>

bool		check_map(t_map map)
{
	long i;

	i = -1;
	while (++i < map.cols * map.rows)
	{
		if (!(map.map[i] == map.empty || map.map[i] == map.obstacle))
			return (false);
	}
	return (true);
}

t_solution	make_solution(int row, int col, int dimension)
{
	t_solution s;

	s.row = row;
	s.col = col;
	s.dimension = dimension;
	return (s);
}

int			min3(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	return ((b < c) ? b : c);
}

t_solution	find_solution(t_map map, int *sum)
{
	t_solution	solution;
	int			row;
	int			col;
	long		off;

	solution.dimension = sum[0];
	row = -1;
	while (++row < map.rows)
	{
		col = -1;
		while (++col < map.cols)
		{
			off = row * map.cols + col;
			if (sum[off] > solution.dimension)
			{
				solution.dimension = sum[off];
				solution.row = row;
				solution.col = col;
			}
		}
	}
	free(sum);
	return (solution);
}

t_solution	solve(t_map map)
{
	int		*sum;
	int		row;
	int		col;
	long	off;

	sum = malloc(map.rows * map.cols * sizeof(int));
	col = -1;
	while (++col < map.cols)
		sum[col] = map.map[col] == map.empty;
	row = 0;
	while (++row < map.rows)
	{
		sum[row * map.cols] = map.map[row * map.cols] == map.empty;
		col = 0;
		while (++col < map.cols)
		{
			off = row * map.cols + col;
			sum[off] = (map.map[off] != map.empty) ? 0 :
			min3(sum[row * map.cols + col - 1], sum[(row - 1) * map.cols + col],
				sum[(row - 1) * map.cols + col - 1]) + 1;
		}
	}
	return (find_solution(map, sum));
}
