/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssantiag <ssantiag@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:15:37 by ssantiag          #+#    #+#             */
/*   Updated: 2021/02/08 11:15:37 by ssantiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"
#include "ft_tools.h"

int		ft_atoi(char *str)
{
	int number;

	number = 0;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (-1);
		number = number * 10 + *str - '0';
		str++;
	}
	return (number);
}

bool	prepare_map(t_map *map)
{
	map->even = malloc(map->cols * sizeof(int));
	map->odd = malloc(map->cols * sizeof(int));
	if (map->even == NULL || map->odd == NULL)
	{
		free(map->even);
		free(map->odd);
		return (false);
	}
	return (true);
}

bool	cleanup(char *mem1, char *mem2)
{
	free(mem1);
	free(mem2);
	return (false);
}

bool	load_map(t_map *map, int fileid)
{
	char	*first_line;
	int		row;
	long	len;

	if ((first_line = read_line(fileid)) == NULL)
		return (false);
	map->cols = ft_strlen(first_line);
	if ((map->map = malloc((map->rows * map->cols + 8) >> 3)) == NULL)
		return (cleanup(first_line, NULL));
	first_line[map->cols] = '\n';
	if (!bitpack(*map, first_line, 0))
		return (cleanup(first_line, map->map));
	row = 0;
	while (++row < map->rows)
	{
		len = read(fileid, first_line, map->cols + 1);
		if (len != map->cols + 1 || !bitpack(*map, first_line, row))
			return (cleanup(first_line, map->map));
	}
	free(first_line);
	return (prepare_map(map));
}

bool	read_map(t_map *map, int fileid)
{
	char	*param_line;
	int		count;

	if ((param_line = read_line(fileid)) == NULL)
		return (false);
	count = ft_strlen(param_line);
	if (count < 4)
	{
		free(param_line);
		return (false);
	}
	map->empty = param_line[count - 3];
	map->obstacle = param_line[count - 2];
	map->full = param_line[count - 1];
	param_line[count - 3] = '\0';
	map->rows = ft_atoi(param_line);
	free(param_line);
	if (map->rows < 1 || map->empty == map->obstacle ||
	map->empty == map->full || map->obstacle == map->full ||
	!(is_print(map->empty) && is_print(map->full) && is_print(map->obstacle)))
		return (false);
	return (load_map(map, fileid));
}
