/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 23:37:14 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/21 16:59:57 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
// # include "bipipe.h"

# define COM 1
# define RE_IN 2
# define RE_OUT 3
# define H_DOC 4
# define APPEND 5
# define ARGV 6
# define NOT 7
# define RE 8

typedef struct	s_com t_com;
typedef struct	s_re t_re;
typedef struct	s_word t_word;
typedef struct	s_set t_set;

struct			s_set
{
	//$A
	char		*name;
	char		*value;
	t_set		*next;
};

typedef struct	s_list
{
	t_com		*head;
	char		**envp;
	char		**path;
	t_set		*set;
}				t_list;

struct			s_re
{
	int			type;
	char		*file;
	t_re		*next;
};

struct			s_com
{
	char		*c;
	char		**path;
	char		**argv;
	t_re		*re_head;
	int			type;
	t_com		*next;
};

/*
** parsing struct
*/

struct			s_word
{
	int			type;
	char		*s;
	t_word		*next;
};

typedef struct	s_words
{
	t_word		*head;
}				t_words;

/*
** parsing
*/

int				ft_split(t_words *words, char *s);
int				parsing_start(char *s, t_list *list);
int				set_list(t_list *list, t_words *words);
int				set_path(t_list *list, char **envp);

int				set_command(t_list *list, char *s);
int				set_command2(t_list *list, char *s, t_com *temp);

int				input_list(t_list *list, char *s);
int				put_argument(t_list *list, char *s);
void			check_redi(t_list *list, char *s);
int				put_re(t_list *list, char *s);


/*
** environment.c
*/

int				set_path(t_list *list, char **envp);
char			**ft_split_envp(char *s);
int				set_path_in_com(t_list *list);
int				set_path_in_com2(t_com *temp, int i, t_list *list);

/*
** utils.c
*/

int				error_list_free(char *s, t_list *list);
void			error_list_free2(t_com *temp);
int				free_words(t_words *words, char *s);
int				error_print(char *s);
int				free_list(t_list *list, char *s);
void			print_list(t_list *list);

/*
** ft_str.c
*/

int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(char *s);
int				ft_strcat_s(char **s1, char **s2);

/*
** set.c
*/

int				check_variable(char *s);

#endif