# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 20:07:16 by seungoh           #+#    #+#              #
#    Updated: 2021/07/28 16:22:37 by seung-eun        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUT		=	minishell
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g
SRCDIR  =	./srcs/
SRCNAME	=	gnl/get_next_line.c\
			gnl/get_next_line_utils.c\
			object/set_object.c\
			object/re_object.c\
			object/com_object.c\
			object/word_object.c\
			object/list_object.c\
			object/addenv_object.c\
			object/his_object.c\
			\
			parsing/ft_split1.c\
			parsing/ft_split2.c\
			parsing/ft_split3.c\
			\
			parsing/ft_str.c\
			parsing/set.c\
			parsing/parsing1.c\
			parsing/parsing2.c\
			parsing/parsing_set.c\
			parsing/utils.c\
			parsing/utils2.c\
			parsing/environment.c\
			parsing/environment2.c\
			parsing/terminal_set.c\
			\
			exec/error.c\
			exec/std_init.c\
			exec/exec.c\
			exec/lst_utils.c\
			exec/pipe_utils.c\
			exec/redirection.c\
			exec/tty_utils.c\
			exec/str_utils.c\
			\
			builtin/builtin.c\
			builtin/echo.c\
			builtin/pwd.c\
			builtin/export.c\
			builtin/export2.c\
			builtin/env.c\
			builtin/unset.c\
			builtin/exit.c\
			\
			signal/signal.c
			
SRCS	=	${addprefix ${SRCDIR}, ${SRCNAME}}
INCDIR	=	./includes/
OBJS	=	${SRCS:.c=.o}

all		: $(OUT)

clean	:
	@rm -rf ${OBJS}

test	:	re
			./${OUT}

.c.o	:
	@${CC} ${CFLAGS} -I ${INCDIR} -c ${<} -o ${<:.c=.o} -I/usr/local/opt/readline/include

${OUT}: ${OBJS}
	@${CC} ${CFLAGS} ${CLIB} -o ${OUT} ${OBJS} -lncurses -lreadline -L/usr/local/opt/readline/lib -I/usr/local/opt/readline/include

fclean	: clean
	@rm -rf	${OUT}

re		: fclean all

.PHONY: all clean fclean re