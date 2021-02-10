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

int			min3(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	return ((b < c) ? b : c);
}

void		store(t_solution *solution, int row, int col, int dimension)
{
	solution->row = row;
	solution->col = col;
	solution->dimension = dimension;
}

bool		solve_rest(t_map map, t_solution *solution, int row)
{
	int		col;
	char	*m;
	int		*prev;
	int		*curr;

	prev = row % 2 ? map.even : map.odd;
	curr = row % 2 ? map.odd : map.even;
	m = map.map + row * (map.cols + 1);
	col = -1;
	while (++col < map.cols)
	{
		if (*m != map.empty && *m != map.obstacle)
			return (false);
		if (col == 0)
			curr[col] = *m++ == map.empty ? 1 : 0;
		else
			curr[col] = *m++ == map.empty ?
				min3(curr[col - 1], prev[col], prev[col - 1]) + 1 : 0;
		if (solution->dimension < curr[col])
			store(solution, row, col, curr[col]);
	}
	return (*m == '\n');
}

bool		solve_first(t_map map, t_solution *solution)
{
	int		col;
	char	*m;

	m = map.map;
	col = -1;
	while (++col < map.cols)
	{
		if (*m != map.empty && *m != map.obstacle)
			return (false);
		map.even[col] = *m++ == map.empty ? 1 : 0;
		if (map.even[col] == 1 && solution->dimension == 0)
			store(solution, 0, col, 1);
	}
	return (*m == '\n');
}

t_solution	solve(t_map map)
{
	t_solution	solution;
	int			row;

	solution.dimension = 0;
	if (!solve_first(map, &solution))
		return (solution);
	row = 0;
	while (++row < map.rows)
	{
		if (!solve_rest(map, &solution, row))
		{
			store(&solution, 0, 0, 0);
			break ;
		}
	}
	return (solution);
}
