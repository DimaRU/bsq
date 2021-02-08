/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssantiag <ssantiag@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:34:44 by ssantiag          #+#    #+#             */
/*   Updated: 2021/02/08 15:34:44 by ssantiag         ###   ########.fr       */
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

char	*return_clear(char *line)
{
	free(line);
	return (NULL);
}

char	*read_line(int fileid)
{
	size_t	alloc_size;
	size_t	i;
	char	*line;

	alloc_size = 64;
	line = malloc(alloc_size);
	i = -1;
	while (line != NULL)
	{
		while (++i < alloc_size)
		{
			if (read(fileid, line + i, 1) != 1)
				return_clear(line);
			if (line[i] == '\n')
			{
				line[i] = '\0';
				return (line);
			}
		}
		line = ft_realloc(line, alloc_size, alloc_size * 2);
		alloc_size *= 2;
	}
	return (NULL);
}
