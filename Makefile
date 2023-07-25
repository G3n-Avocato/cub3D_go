# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lamasson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 13:34:21 by lamasson          #+#    #+#              #
#    Updated: 2023/07/25 13:58:49 by lamasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang

CFLAGS	= -Wall -Wextra -Werror -g

RM		= rm -rf

NAME	= cube3D

SRCS	= ft_parsing.c \
		  ft_parsing_color.c \
		  ft_parsing_texture.c

OBJS	= ${SRCS:%.c=%.o}

LIBFT	= libft

all:	${NAME}

${NAME}: ${OBJS} 
		make bonus -C ${LIBFT}
		${CC} ${CFLAGS} -L ${LIBFT} -lft -o ${NAME} ${OBJS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
		make -s -C ${LIBFT} clean
		${RM} ${OBJS}

fclean: clean
		make -s -C ${LIBFT} fclean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re

