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
	char	*line;

	line = (char *)map.even;
	row = -1;
	while (++row < map.rows)
	{
		bitunpack(map, line, row);
		if (row > solution.row - solution.dimension && row <= solution.row)
		{
			col = solution.col - solution.dimension;
			while (++col <= solution.col)
			{
				line[col] = map.full;
			}
		}
		write(STDOUT_FILENO, line, map.cols + 1);
	}
}
