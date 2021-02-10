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

void		store(t_solution *solution, int row, int col, int dimension)
{
	solution->row = row;
	solution->col = col;
	solution->dimension = dimension;
}

void		solve_rest(t_map map, t_solution *solution, int row)
{
	int		col;
	int		*prev;
	int		*curr;
	long	off;

	prev = row % 2 ? map.even : map.odd;
	curr = row % 2 ? map.odd : map.even;
	col = -1;
	while (++col < map.cols)
	{
		off = row * map.cols + col;
		if (map.map[off >> 3] & 1 << (off & 0x7))
			curr[col] = 0;
		else if (col == 0)
			curr[col] = 1;
		else
		{
			curr[col] = curr[col - 1] < prev[col] ? curr[col - 1] : prev[col];
			curr[col] = curr[col] < prev[col - 1] ? curr[col] : prev[col - 1];
			curr[col]++;
		}
		if (solution->dimension < curr[col])
			store(solution, row, col, curr[col]);
	}
}

void		solve_first(t_map map, t_solution *solution)
{
	int		col;
	long	off;

	col = -1;
	while (++col < map.cols)
	{
		off = map.cols + col;
		map.even[col] = (map.map[off >> 3] & (1 << (off & 0x7))) ? 1 : 0;
		if (map.even[col] == 1 && solution->dimension == 0)
			store(solution, 0, col, 1);
	}
}

t_solution	solve(t_map map)
{
	t_solution	solution;
	int			row;

	solution.dimension = 0;
	solve_first(map, &solution);
	row = 0;
	while (++row < map.rows)
		solve_rest(map, &solution, row);
	return (solution);
}
