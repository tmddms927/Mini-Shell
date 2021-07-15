#ifndef BIPIPE_H
# define BIPIPE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
# include "header.h"

# define CHILD 0
# define READ 0
# define WRITE 1

# ifndef BUFFERSIZE
# define BUFFERSIZE 4096
# endif
/*==========================================*/
// # define COM 1
// # define RE_IN 2
// # define RE_OUT 3
// # define H_DOC 4
// # define APPEND 5
// # define ARGV 6
// # define NOT 7

// typedef struct    s_com t_com;
// typedef struct    s_re t_re;


// typedef struct    s_list
// {
//     t_com        *head;
// }                t_list;

// struct    s_re
// {
//     int            type;
//     char        *file;
//     t_re        *next;
// };

// struct            s_com
// {
//     char        *c;
//     char        **path;
//     char        **argv;
//     t_re        *re_head;
//     int            type;
//     char        **env;
//     t_com        *next;
// };
/*==========================================*/

/*==========================================*/

//lst_utils
int			lst_len(t_com *command);
//error
void		handle_error(char *str);
void		handle_message(char *str);
//exec
void		exec(t_list *command_info);
void		exec_multy_command(t_com *command_info, char **envp);
void		command(t_com *command_node, char **envp);
void		command_exit(t_com *command_node, char **envp);
void		command_out_pipe(t_com *command_node, char **envp);
//redirection
void		redirect(t_re *redir_list);
int		re_out(char *file);
int		re_in(char *file);
int		append(char *file);
void	h_doc(char *code);
//str_utils
char		*ft_strjoin(char *cont, char *s);
void	ft_memset(char *p, unsigned int size);
int		ft_memmove(char *dest, char *src);
// static int		ft_strlen(char *s);
// static int		ft_strcmp(char *s1, char *s2);

#endif