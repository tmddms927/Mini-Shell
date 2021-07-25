#ifndef EXEC_H
# define EXEC_H

# include "header.h"

# define CHILD 0
# define READ 0
# define WRITE 1

# define TRUE 1
# define FALSE 0

# ifndef BUFFERSIZE
# define BUFFERSIZE 4096
# endif

typedef unsigned int	t_bool;


//lst_utils
int			lst_len(t_com *command);
//error
void		handle_error(char *str);
void		handle_message(char *str);
void	snatch_error(int error_num);
void	exit_safe(char *func_name, char *obj, int err_num, int exit_num);
void	command_not_found(char *func_name, char *obj);
//exec
//
void		separate_stream(int (*fp)(t_com *, char **), t_list *command_list);
int		exec(t_com *command_info, char **envp);
void		command(t_com *command_node, char **envp);
int	    	exec_to(int *to, t_com *command_node, char **envp);
void from_pipe(int *pipefd);
void to_pipe(int *pipefd);
//redirection
void		redirect(t_re *redir_list);
void		re_out(char *file);
void		re_in(char *file);
void		append(char *file);
void	h_doc(char *code);
void	find_tty(void);
void	read_endl(int fd, char *code);
//str_utils
char		*ft_strjoin(char *cont, char *s);
void	ft_memset(char *p, unsigned int size);
int		ft_memmove(char *dest, char *src);
// static int		ft_strlen(char *s);
// static int		ft_strcmp(char *s1, char *s2);
//file_utils
// t_FILE  *custom_fopen(char *pathname, int flag, int mode);

#endif
