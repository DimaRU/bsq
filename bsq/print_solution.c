/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssantiag <ssantiag@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:18:33 by ssantiag          #+#    #+#             */
/*   Updated: 2021/02/08 13:18:33 by ssantiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bsq.h"
#include "ft_tools.h"

void	print_solution(t_solution solution, t_map map)
{
	int		row;
	int		col;
	long	offset;

	row = solution.row - 1;
	while (++row < solution.row + solution.dimension)
	{
		col = solution.col - 1;
		while (++col < solution.col + solution.dimension)
		{
			offset = (long)row * map.cols + col;
			map.map[offset] = map.full;
		}
	}
	row = -1;
	while (++row < map.rows)
	{
		offset = (long)row * map.cols;
		write(STDOUT_FILENO, map.map + offset, map.cols);
		ft_putstr("\n");
	}
}
