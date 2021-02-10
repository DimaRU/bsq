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

bool		solve_rest(t_map map, t_solution *solution, int row, char *m)
{
	int		col;
	int		*prev;
	int		*curr;

	prev = row % 2 ? map.even : map.odd;
	curr = row % 2 ? map.odd : map.even;
	col = -1;
	while (++col < map.cols)
	{
		if (*m != map.empty && *m != map.obstacle)
			return (false);
		if (*m++ != map.empty)
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
		if (!solve_rest(map, &solution, row, map.map + row * (map.cols + 1)))
		{
			store(&solution, 0, 0, 0);
			break ;
		}
	}
	return (solution);
}
