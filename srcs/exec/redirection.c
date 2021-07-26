#include "exec.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int	redirect(char *tty, t_re *redir_list)
{
	int	ret;

	while (redir_list)
	{
		if (redir_list->type == RE_OUT)
			ret = re_out(redir_list->file);
		else if (redir_list->type == RE_IN)
			ret = re_in(redir_list->file);
		else if (redir_list->type == H_DOC)
			ret = h_doc(tty, redir_list->file);
		else if (redir_list->type == APPEND)
			ret = append(redir_list->file);
		if (ret)
			return (ret);
		redir_list = redir_list->next;
	}
	return (0);
}

int	re_out(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0755);
	if (fd < 0)
		return (return_error("minishell", file, errno, 1));
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (return_error("minishell", file, errno, 1));
	return (0);
}

int	re_in(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (return_error("minishell", file, errno, 1));
	if (dup2(fd, STDIN_FILENO) < 0)
		return (return_error("minishell", file, errno, 1));
	return (0);
}

int	append(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0755);
	if (fd < 0)
		return (return_error("minishell", file, errno, 1));
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (return_error("minishell", file, errno, 1));
	return (0);
}

int	h_doc(char *tty, char *code)
{
	int		fd;
	char	*tempfile;

	if (!code)
		return (return_error("minishell", code, errno, 258));
	tempfile = "/tmp/TTT";
	stdin_init(tty);
	fd = open(tempfile, O_RDWR | O_TRUNC | O_CREAT, 0755);
	if (fd < 0)
		return (return_error("minishell", tempfile, errno, 1));
	read_endl(fd, code);
	close(fd);
	fd = open(tempfile, O_RDONLY);
	if (fd < 0)
		return (return_error("minishell", tempfile, errno, 1));
	if (dup2(fd, STDIN_FILENO) < 0)
		return (return_error("minishell", "dup2", errno, 1));
	close(fd);
	if (unlink(tempfile) < 0)
		return (return_error("minishell", "unlink", errno, 1));
	return (0);
}
