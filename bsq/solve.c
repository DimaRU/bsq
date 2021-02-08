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

bool	check_map(t_map map)
{
	int i;

	i = -1;
	while (++i < map.cols * map.rows)
	{
		if (!(map.map[i] == map.empty || map.map[i] == map.obstacle))
			return (false);
	}
	return (true);
}

int		is_obstacle(t_map map, int row, int col)
{
	int offset;

	offset = row * map.cols + col;
	return (map.map[offset] == map.obstacle);
}

void	solve(t_map map)
{

}
