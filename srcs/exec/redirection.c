#include "exec.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

void	redirect(t_re *redir_list)
{
	while (redir_list)
	{
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

void	re_out(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0755);
	if (fd < 0)
		exit_safe("minishell", file, errno, 1);
	if (dup2(fd, STDOUT_FILENO) < 0)
		exit_safe("minishell", file, errno, 1);
}

void	re_in(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_safe("minishell", file, errno, 1);
	if (dup2(fd, STDIN_FILENO) < 0)
		exit_safe("minishell", file, errno, 1);
}

void	append(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0755);
	if (fd < 0)
		exit_safe("minishell", file, errno, 1);
	if (dup2(fd, STDOUT_FILENO) < 0)
		exit_safe("minishell", file, errno, 1);
}

void	h_doc(char *code)
{
	int		fd;
	char	*tempfile;

	if (!code)
		exit_safe("minishell", code, errno, 258);
	tempfile = "/tmp/TTT";
	find_tty();
	fd = open(tempfile, O_RDWR | O_TRUNC | O_CREAT, 0755);
	if (fd < 0)
		exit_safe("minishell", tempfile, errno, 1);
	read_endl(fd, code);
	close(fd);
	fd = open(tempfile, O_RDONLY);
	if (fd < 0)
		exit_safe("minishell", tempfile, errno, 1);
	if (dup2(fd, STDIN_FILENO) < 0)
		exit_safe("minishell", "stdin", errno, 1);
	close(fd);
	unlink(tempfile);
}
