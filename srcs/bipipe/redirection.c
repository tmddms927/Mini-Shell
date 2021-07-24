#include "bipipe.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

void		redirect(t_re *redir_list)
{
	while (redir_list)
	{
		// dprintf(2, "%d", redir_list->type);
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
	
	fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0755);

	if ((ret = dup2(fd, STDOUT_FILENO)) < 0)
	{
		handle_error("append");
		return (-1);
	}
	return (ret);
}

void		h_doc(char *code)
{
	int		fd;
	char	*s;
	char	*cont;
	char	prompt[3] = "> \0";

	cont = 0;
	fd = open("tmp", O_RDWR| O_TRUNC | O_CREAT, 0755);
	while (1)
	{
		s = readline(prompt);
		if (!ft_strcmp(s, code))
		{
			free(s);
			break ;
		}
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
	close(fd);
	fd = open("tmp",	O_RDONLY);
	if (dup2(fd, STDIN_FILENO) < 0)
		handle_error("h_doc");
	close(fd);
	unlink("tmp");
}