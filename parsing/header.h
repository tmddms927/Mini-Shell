/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 23:37:14 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/07 07:17:33 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define COM 1
# define RE_IN 2
# define RE_OUT 3
# define H_DOC 4
# define APPEND 5
# define PIPE 6

typedef struct	s_com t_com;

typedef struct	s_list
{
	t_com		*head;
}				t_list;

typedef struct	s_re
{
	int			type;
	char		*file;
}				t_re;

struct			s_com
{
	char		*c;
	char		**path;
	char		**argv;
	t_re		*re_head;
	t_com		*next;
};

/*
** parsing
*/

int				parsing_start(char *s, t_list *list);
char			**ft_split(char const *s);
int				ft_strcmp(const char *s1, const char *s2);
int				set_list(t_list *list, char **word);
char			*set_command(char *word);

/*
** object.c
*/

int				oadd(t_list *list);
t_com			*olast(t_list *list);
t_list			*init_list(void);

/*
** utils.c
*/

int				error_free(char *s, t_list *list);
size_t			ft_strlen(char *s);
char			*ft_strcat(char *s1, char s2);

#endif