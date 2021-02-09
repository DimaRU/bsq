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

bool	cleanup(char *memory)
{
	free(memory);
	return (false);
}

bool	load_map(t_map *map, int fileid)
{
	char	*first_line;
	long	i;
	int		len;

	if ((first_line = read_line(fileid)) == NULL)
		return (false);
	map->cols = ft_strlen(first_line);
	if ((map->map = malloc((long)map->rows * map->cols + 1)) == NULL)
		return (cleanup(first_line));
	i = -1;
	while (++i < map->cols)
		map->map[i] = first_line[i];
	free(first_line);
	i = 0;
	while (++i < map->rows)
	{
		len = (int)read(fileid, map->map + map->cols * i, map->cols + 1);
		if (len != map->cols + 1 || map->map[map->cols * (i + 1)] != '\n')
			return (cleanup(map->map));
	}
	return (true);
}

bool	is_print(char c)
{
	return (c >= ' ' && c <= '\x7e');
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
