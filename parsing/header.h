/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 23:37:14 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/07 05:35:09 by seungoh          ###   ########.fr       */
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

typedef struct	s_com t_com;

struct			s_com
{
	int			type;
	char		**path;
	char		**argv;
	t_com		*next;
};

typedef struct	s_list
{
	t_com		*head;
}				t_list;

/*
** parsing
*/

t_list			parsing_start(char *s, t_list list);
char			**ft_split(char const *s);
int				ft_strcmp(const char *s1, const char *s2);
void			set_command(char **words, t_list list);

/*
** utils.c
*/

int				oadd(t_list list);
// t_com			*com(t_list list);
int				error_free(char *s, t_list list);

#endif