/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssantiag <ssantiag@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:57:41 by ssantiag          #+#    #+#             */
/*   Updated: 2021/02/06 16:57:41 by ssantiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "bsq.h"
#include "ft_tools.h"

bool	is_print(char c)
{
	return (c >= ' ' && c <= '\x7e');
}

bool	process_file(int fileid)
{
	t_map		map;
	t_solution	solution;

	if (!read_map(&map, fileid))
	{
		put_map_error();
		return (false);
	}
	solution = solve(map);
	if (solution.dimension != 0)
		print_solution(solution, map);
	else
		put_map_error();
	free(map.map);
	free(map.even);
	free(map.odd);
	return (true);
}

int		main(int argc, char *argv[])
{
	int	fileid;
	int i;

	if (argc == 1)
	{
		if (!process_file(STDIN_FILENO))
			exit(1);
	}
	i = 0;
	while (++i < argc)
	{
		fileid = open(argv[i], O_RDONLY);
		if (fileid == -1)
		{
			put_map_error();
			continue ;
		}
		process_file(fileid);
		close(fileid);
	}
	return (0);
}
