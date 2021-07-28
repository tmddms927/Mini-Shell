/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:54:42 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/28 21:58:22 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 4
# define _UP 4283163
# define _DOWN 4348699

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "header.h"

int		get_next_line(int fd, char **line, t_list *list, int check);
int		check_line(char *backup, int *end_index);
int		split_line(char **backup, char **line, int end_index);
int		check_return(char **backup, char **line, int read_size);

size_t	gnl_ft_strlen(const char *s);
char	*gnl_ft_strjoin(char *s1, char *s2);
char	*single_str(char *s);
char	*single_str2(char *s);

int		buf_check(int *c, int *idx, char **s, t_list *list);
void	save_input_mode(t_list *list);
void	set_input_mode(t_list *list);
void	reset_input_mode(t_list *list);

#endif