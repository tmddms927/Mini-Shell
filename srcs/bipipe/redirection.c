#include "bipipe.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

void		redirect(t_re *redir_list)
{
	write(2, "A", 1); 
	while (redir_list)
	{
		dprintf(2, "%d", redir_list->type);
		if (redir_list->type == RE_OUT)
			re_out(redir_list->file);
		else if (redir_list->type == RE_IN)
			re_in(redir_list->file);
		else if (redir_list->type == H_DOC)
			h_doc(redir_list->file);
		else if (redir_list->type == APPEND)
			append(redir_list->file);
		redir_list = redir_list->next;
	}
}

int		re_out(char *file)
{
	int fd;
	int ret;
	
	write(2, "B", 1);
	fd = open(file, O_WRONLY| O_TRUNC | O_CREAT, 0755);
	if ((ret = dup2(fd, STDOUT_FILENO)) < 0)
		return (-1);
	return (ret);
}

int		re_in(char *file)
{
	int fd;
	int ret;
	
	fd = open(file,	O_RDONLY);
	if ((ret = dup2(fd, STDIN_FILENO)) < 0)
		return (-1);
	return (ret);
}

int		append(char *file)
{
	int fd;
	int ret;
	
	fd = open(file, O_APPEND);
	if ((ret = dup2(fd, STDOUT_FILENO)) < 0)
		return (-1);
	return (ret);
}

void		h_doc(char *code)
{
	int		fd;
	char	*s;
	char	*cont;
	char	prompt[2] = "> ";

	cont = 0;
	fd = open("tmp", O_WRONLY| O_TRUNC | O_CREAT, 0755);
	while (1)
	{
		s = readline(prompt);
		if (!ft_strcmp(s, code))
		{
			free(s);
			break ;
		}
		ft_strjoin(cont, s);
	}
	write(fd, cont, ft_strlen(cont));
	dup2(fd, STDIN_FILENO);
	unlink("tmp");
}

