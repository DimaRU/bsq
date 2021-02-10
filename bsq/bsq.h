/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssantiag <ssantiag@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:58:15 by ssantiag          #+#    #+#             */
/*   Updated: 2021/02/06 16:58:15 by ssantiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <stdbool.h>

typedef struct	s_map
{
	long		cols;
	long		rows;
	char		empty;
	char		obstacle;
	char		full;
	char		*map;
	int			*even;
	int			*odd;
}				t_map;

typedef struct	s_solution
{
	int			col;
	int			row;
	int			dimension;
}				t_solution;

void			put_map_error(void);
bool			read_map(t_map *map, int fileid);
bool			check_map(t_map map);
t_solution		solve(t_map map);
void			print_solution(t_solution solution, t_map map);
char			*read_line(int fileid);

#endif
