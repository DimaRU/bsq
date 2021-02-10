# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: ssantiag <ssantiag@student.21-school.ru>   +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2021/02/08 13:31:11 by ssantiag          #+#    #+#             #
#   Updated: 2021/02/08 13:31:11 by ssantiag         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME = bsq
INCLUDE = includes
SRC  =	main.c \
		print_solution.c \
		put_map_error.c \
		read_map.c \
		solve.c \
		read_line.c \
		ft_putstr_err.c \
		ft_strlen.c

OBJ  	= ${SRC:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
%.o: %.c bsq.h ft_tools.h
		$(CC) -c $(CFLAGS) -o $@ $<
$(NAME): ${OBJ}
		gcc -o $@ ${OBJ}
all:	${NAME}
clean:
		rm -f ${OBJ}
fclean:	clean
		rm -f ${NAME}
re:		fclean all

.PHONY : clean all fclean re
