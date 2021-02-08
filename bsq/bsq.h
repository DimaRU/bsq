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
	int			cols;
	int			rows;
	char		empty;
	char		obstacle;
	char		full;
	char		*map;
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

#endif
