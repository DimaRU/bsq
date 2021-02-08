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

bool		check_map(t_map map)
{
	long i;

	i = -1;
	while (++i < (long)map.cols * map.rows)
	{
		if (!(map.map[i] == map.empty || map.map[i] == map.obstacle))
			return (false);
	}
	return (true);
}

int			is_obstacle(t_map map, int row, int col)
{
	int offset;

	offset = row * map.cols + col;
	return (map.map[offset] == map.obstacle);
}

int			find_max_square(t_map map, int start_row, int start_col)
{
	int row;
	int col;
	int dim;

	dim = 0;
	while (start_row + dim < map.rows && start_col + dim < map.cols)
	{
		col = start_col - 1;
		while (++col <= start_col + dim)
		{
			if (is_obstacle(map, start_row + dim, col))
				return (dim);
		}
		row = start_row - 1;
		while (++row <= start_row + dim)
		{
			if (is_obstacle(map, row, start_col + dim))
				return (dim);
		}
		dim++;
	}
	return (dim);
}

t_solution	solve(t_map map)
{
	t_solution	solution;
	int			row;
	int			col;
	int			dim;

	solution.dimension = 0;
	row = -1;
	while (++row < map.rows)
	{
		if (row + solution.dimension >= map.rows)
			return (solution);
		col = -1;
		while (++col < map.cols)
		{
			if (col + solution.dimension >= map.cols)
				break ;
			if ((dim = find_max_square(map, row, col)) > solution.dimension)
			{
				solution.dimension = dim;
				solution.row = row;
				solution.col = col;
			}
		}
	}
	return (solution);
}
