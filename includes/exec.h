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



//lst_utils
int			lst_len(t_com *command);
//error
void	handle_message(char *str);
void	snatch_error(int error_num, t_list *command_list);
void	exit_safe(char *func_name, char *obj, int err_num, int exit_num);
void	command_not_found(char *func_name, char *obj);
int	return_error(char *func_name, char *obj, int err_num, int exit_num);
//exec
// int	multy_command(t_list * list);
// int	command(t_list *list, t_com *com, t_bool next);
// int	exec(t_com *command_node, int *pipe, char **envp);
int	exec(t_list *list);
int	command(t_list *list, t_com *com);
int	exec_to(t_list * list, t_com *com, int *to);
int do_non_builtin(t_list *list, t_com *com);

//pipe_utils
int from_pipe(int *pipefd);
int to_pipe(int *pipefd);
//redirection
int		redirect(char *tty, t_re *redir_list);
int		re_out(char *file);
int		re_in(char *file);
int		append(char *file);
int		h_doc(char *tty, char *code);
void	find_tty(void);
void	read_endl(int fd, char *code);
//str_utils
char		*ft_strjoin(char *cont, char *s);
void	ft_memset(char *p, unsigned int size);
int		ft_memmove(char *dest, char *src);
//std_init
int stdio_init(char *tty);
int stdout_init(char *tty);
int stdin_init(char *tty);
int stderr_init(char *tty);



#endif
