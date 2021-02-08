/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssantiag <ssantiag@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 01:39:09 by ssantiag          #+#    #+#             */
/*   Updated: 2021/01/22 01:39:09 by ssantiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	char *end_pointer;

	end_pointer = str;
	while (*end_pointer != '\0')
		end_pointer++;
	return ((int)(end_pointer - str));
}
