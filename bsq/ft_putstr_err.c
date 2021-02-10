/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssantiag <ssantiag@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 01:39:13 by ssantiag          #+#    #+#             */
/*   Updated: 2021/02/10 21:45:03 by ssantiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_err(char *str)
{
	char *end_pointer;

	if (str == NULL)
		return ;
	if (*str == '\0')
		return ;
	end_pointer = str;
	while (*end_pointer != '\0')
		end_pointer++;
	write(STDERR_FILENO, str, end_pointer - str);
}
