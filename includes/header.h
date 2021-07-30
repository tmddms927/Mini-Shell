/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwan <hwan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 23:37:14 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/30 15:23:06 by hwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
// # include "bipipe.h"

# define COM 1
# define RE_IN 2
# define RE_OUT 3
# define H_DOC 4
# define APPEND 5
# define ARGV 6
# define NOT 7
# define RE 8
# define TRUE 1
# define FALSE 0

typedef struct s_com	t_com;
typedef struct s_re		t_re;
typedef struct s_word	t_word;
typedef struct s_set	t_set;
typedef unsigned int	t_bool;
typedef struct s_env	t_env;
typedef struct s_his	t_his;

struct				s_set
{
	char			*name;
	char			*value;
	t_set			*next;
};

struct				s_env
{
	char			*name;
	char			*s;
	t_env			*next;
};

typedef struct s_his_stack
{
	t_his			*head;
}					t_his_stack;

struct				s_his
{
	t_his			*before;
	char			*s;
	t_his			*next;
};

typedef struct s_list
{
	t_com			*head;
	char			**envp;
	char			**path;
	t_set			*set;
	char			*tty;
	t_env			*env;
	t_his_stack		*his;
	t_his			*his_here;
	int				his_check;
	struct termios	org_term;
	struct termios	new_term;
}					t_list;

struct				s_re
{
	int				type;
	char			*file;
	t_re			*next;
};

struct				s_com
{
	char			*c;
	char			**path;
	char			**argv;
	t_re			*re_head;
	int				type;
	t_com			*next;
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

typedef struct s_words
{
	t_word		*head;
}				t_words;

typedef struct s_pars
{
	int			type;
	int			i;
	char		*orig_s;
	int			orig_len;
	int			pos;
	t_words		*words;
}				t_pars;

/*
** parsing
*/

int				ft_split(t_words *words, char *s, t_list *list);
int				parsing_start(char *s, t_list *list);
int				set_list(t_list *list, t_words *words);

int				set_command(t_list *list, char *s);
int				set_command2(t_list *list, char *s, t_com *temp);

int				input_list(t_list *list, char *s);
int				put_argument(t_list *list, char *s);
void			check_redi(t_list *list, char *s);
int				put_re(t_list *list, char *s);
int				check_list_error(t_list *list);

/*
** set parsing
*/

int				variable_in_set(t_pars *pars, t_list *list, char **s);

/*
** environment.c
*/

int				set_path(t_list *list);
char			**ft_split_envp(char *s);
int				set_path_in_com(t_list *list);
int				set_path_in_com2(t_com *temp, int i, t_list *list);
void			free_path(t_list *list);

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
int				ft_strncmp(const char *s1, const char *s2, unsigned int size);
size_t			ft_strlen(char *s);
int				ft_strcat_s(char **s1, char **s2);

/*
** set.c
*/

int				set_set(t_list *list);
int				add_set_error_code(t_list *list);
int				check_variable(char *s);
int				save_set(t_list *list, char *s);
void			print_set(t_list *list);

/*
** builtin function
*/

int				do_builtin(t_list *list, t_com *com);
int				export(t_list *list, t_com *com);
int				export_argv(t_list *list, t_com *com);
int				set_s_check(char *s);
int				input_env(t_list *list, char *s, char *name);
int				update_env(t_list *list, char *s, char *name);
int				unset(t_list *list, t_com *com);
int				env(t_list *list);
int				ft_exit(t_com *com);
int				echo(char **argv, int check);
t_bool			check_flag(char *argv, char c);
int				putstr(char *str, int fd);
int				pwd(void);
int				cd(t_list *list, char **argv);
int				mv_home(t_list *list);
t_bool			get_home(char *path, t_list *list);
int				set_curpath(char *curpath, char *dir, t_list *list);
t_bool			not_need_sl(char *curpath);
t_bool			dot_handler(char *curpath);
t_bool			dot_dot_handler(char *curpath);
void			ft_bzero(char *s, unsigned int size);
int				ft_pathjoin(char *dest, char *path, char *dir);

int				init_signal_can(void);
int				init_signal_non(void);
void			ctrl_c_non(int signo);

#endif
