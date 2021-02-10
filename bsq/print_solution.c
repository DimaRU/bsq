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

	row = -1;
	while (++row <= map.rows)
	{
		if (row > solution.row - solution.dimension && row <= solution.row)
		{
			col = solution.col - solution.dimension;
			while (++col <= solution.col)
			{
				offset = row * (map.cols + 1) + col;
				map.map[offset] = map.full;
			}
		}
		write(STDOUT_FILENO, map.map + row * (map.cols + 1), map.cols + 1);
	}
}
