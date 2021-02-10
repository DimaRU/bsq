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

void		solve_rest(t_map map, t_solution *solution)
{
	int		row;
	int		col;
	char	*m;
	int		*prev;
	int		*curr;

	row = 0;
	while (++row < map.rows)
	{
		prev = row % 2 ? map.even : map.odd;
		curr = row % 2 ? map.odd : map.even;
		m = map.map + row * (map.cols + 1);
		col = 0;
		curr[col] = *m++ == map.empty ? 1 : 0;
		if (curr[col] == 1 && solution->dimension == 0)
			store(solution, row, col, 1);
		while (++col < map.cols)
		{
			curr[col] = *m++ == map.empty ?
				min3(curr[col - 1], prev[col], prev[col - 1]) + 1 : 0;
			if (solution->dimension < curr[col])
				store(solution, row, col, curr[col]);
		}
		m++;
	}
}

void		solve_first(t_map map, t_solution *solution)
{
	int		col;

	col = -1;
	while (++col < map.cols)
	{
		map.even[col] = map.map[col] == map.empty ? 1 : 0;
		if (map.even[col] == 1 && solution->dimension == 0)
			store(solution, 0, col, 1);
	}
}

t_solution	solve(t_map map)
{
	t_solution	solution;

	solution.dimension = 0;
	solve_first(map, &solution);
	solve_rest(map, &solution);
	return (solution);
}
