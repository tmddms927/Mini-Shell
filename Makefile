# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 20:07:16 by seungoh           #+#    #+#              #
#    Updated: 2021/07/08 20:15:40 by seungoh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUT		=	minishell
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
#-lreadline
SRCDIR  =	./srcs/
SRCNAME	=	parsing/ft_split.c\
			parsing/ft_strcmp.c\
			parsing/object.c\
			parsing/parsing1.c\
			parsing/parsing2.c\
			parsing/parsing3.c\
			parsing/utils.c
SRCS	=	${addprefix ${SRCDIR}, ${SRCNAME}}
INCDIR	=	./includes/
OBJS	=	${SRCS:.c=.o}

all		: $(OUT)

test	:	re
			./${OUT} "cat >a|'$abc'"

.c.o	:
	${CC} ${CFLAGS} -I ${INCDIR} -c ${<} -o ${<:.c=.o}

${OUT}: ${OBJS}
	${CC} ${CFLAGS} ${CLIB} -o ${OUT} ${OBJS}

clean	:
	rm -rf ${OBJS}

fclean	: clean
	rm -rf	${OUT}

re		: fclean all

.PHONY: all clean fclean re