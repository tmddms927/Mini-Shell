# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 20:07:16 by seungoh           #+#    #+#              #
#    Updated: 2021/07/13 05:12:24 by seungoh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUT		=	minishell
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g
SRCDIR  =	./srcs/
SRCNAME	=	parsing/ft_split1.c\
			parsing/ft_split2.c\
			parsing/ft_split3.c\
			parsing/t_words.c\
			parsing/ft_strcmp.c\
			parsing/object.c\
			parsing/parsing1.c\
			parsing/parsing2.c\
			parsing/utils.c\
			parsing/utils2.c
SRCS	=	${addprefix ${SRCDIR}, ${SRCNAME}}
INCDIR	=	./includes/
OBJS	=	${SRCS:.c=.o}

all		: $(OUT)

clean	:
	@rm -rf ${OBJS}

test	:	re
			./${OUT} "cat >a|'$abc'"
			@make clean

.c.o	:
	@${CC} ${CFLAGS} -I ${INCDIR} -c ${<} -o ${<:.c=.o}

${OUT}: ${OBJS}
	@${CC} ${CFLAGS} ${CLIB} -o ${OUT} ${OBJS} -lreadline

fclean	: clean
	@rm -rf	${OUT}

re		: fclean all

.PHONY: all clean fclean re