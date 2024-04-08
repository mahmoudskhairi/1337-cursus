# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 07:27:09 by mskhairi          #+#    #+#              #
#    Updated: 2024/04/08 08:50:48 by mskhairi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_strlen.c ft_calloc.c ft_printf.c ft_free.c ft_atoi.c
OBJ = ${SRC:.c=.o}
NAME = utils.a

all: ${NAME} 

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}

%.o:%.c utils.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME} ${OBJ} 

re: fclean all

.SILENT: