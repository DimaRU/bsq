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

t_solution	create_solution(int row, int col, int dimension)
{
	t_solution s;

	s.row = row;
	s.col = col;
	s.dimension = dimension;
	return (s);
}

t_solution	find_max_square(t_map map, int start_row, int start_col)
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
				return (create_solution(start_row, start_col, dim));
		}
		row = start_row - 1;
		while (++row <= start_row + dim)
		{
			if (is_obstacle(map, row, start_col + dim))
				return (create_solution(start_row, start_col, dim));
		}
		dim++;
	}
	return (create_solution(start_row, start_col, dim));
}

t_solution	solve(t_map map)
{
	t_solution	best;
	t_solution	current;
	int			row;
	int			col;

	best.dimension = 0;
	row = -1;
	while (++row < map.rows)
	{
		if (row + best.dimension >= map.rows)
			return (best);
		col = -1;
		while (++col < map.cols)
		{
			if (col + best.dimension >= map.cols)
				break ;
			current = find_max_square(map, row, col);
			if (current.dimension > best.dimension)
				best = current;
		}
	}
	return (best);
}
