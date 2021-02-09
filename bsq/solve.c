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
	while (++i < map.cols * map.rows)
	{
		if (!(map.map[i] == map.empty || map.map[i] == map.obstacle))
			return (false);
	}
	return (true);
}

t_solution	make_solution(int row, int col, int dimension, int next_col)
{
	t_solution s;

	s.row = row;
	s.col = col;
	s.dimension = dimension;
	s.next_col = next_col;
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
			if (map.map[(start_row + dim) * map.cols + col] == map.obstacle)
				return (make_solution(start_row, start_col, dim, col + 1));
		}
		row = start_row - 1;
		while (++row <= start_row + dim)
		{
			if (map.map[row * map.cols + start_col + dim] == map.obstacle)
				return (make_solution(start_row, start_col, dim,
									start_col + dim + 1));
		}
		dim++;
	}
	return (make_solution(start_row, start_col, dim, (int)map.cols));
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
		col = 0;
		while (col < map.cols)
		{
			if (col + best.dimension >= map.cols)
				break ;
			current = find_max_square(map, row, col);
			if (current.dimension > best.dimension)
				best = current;
			col = current.next_col;
		}
	}
	return (best);
}
