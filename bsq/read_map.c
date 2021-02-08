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

char	*ft_realloc(char *memory, size_t old_size, size_t size)
{
	char *new_alloc;
	char *ptr;

	new_alloc = malloc(size);
	if (new_alloc == NULL)
	{
		free(memory);
		return (NULL);
	}
	ptr = new_alloc;
	while (old_size-- > 0)
		*ptr++ = *memory++;
	return (new_alloc);
}

char	*read_line(int fileid)
{
	size_t	alloc_size;
	size_t	i;
	char	*line;

	alloc_size = 64;
	if ((line = malloc(alloc_size)) == NULL)
		return (NULL);
	i = -1;
	while (true)
	{
		while (++i < alloc_size)
		{
			read(fileid, line + i, 1);
			if (line[i] == '\n')
			{
				line[i] = '\0';
				return (line);
			}
		}
		line = ft_realloc(line, alloc_size, alloc_size * 2);
		alloc_size *= 2;
		if (line == NULL)
			return (NULL);
	}
}

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

bool	load_map(t_map *map, int fileid)
{
	char	*first_line;
	int		i;
	int		len;

	if ((first_line = read_line(fileid)) == NULL)
		return (false);
	map->cols = ft_strlen(first_line);
	if ((map->map = malloc(map->rows * map->cols + 1)) == NULL)
		return (false);
	i = -1;
	while (++i < map->cols)
		map->map[i] = first_line[i];
	free(first_line);
	i = 0;
	while (++i < map->rows)
	{
		len = (int)read(fileid, &map->map[map->cols * i], map->cols + 1);
		if (len != map->cols + 1 || map->map[map->cols * (i + 1)] != '\n')
		{
			free(map->map);
			return (false);
		}
	}
	return (true);
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
		return (true);
	}
	map->empty = param_line[count - 3];
	map->obstacle = param_line[count - 2];
	map->full = param_line[count - 1];
	param_line[count - 3] = '\0';
	map->rows = ft_atoi(param_line);
	free(param_line);
	if (map->rows == -1 || map->empty == map->obstacle ||
			map->empty == map->full || map->obstacle == map->full)
		return (false);
	return (load_map(map, fileid));
}
