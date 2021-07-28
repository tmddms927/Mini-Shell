#include "exec.h"
#include <fcntl.h>
#include <errno.h>

int	stdio_init(char *tty)
{
	if (stdin_init(tty))
		return (1);
	if (stdout_init(tty))
		return (1);
	if (stderr_init(tty))
		return (1);
	return (0);
}

int	stdout_init(char *tty)
{
	int	fd;

	if (!isatty(STDOUT_FILENO))
	{
		fd = open(tty, O_RDWR);
		if (fd < 0)
			return (return_error("minishell", "stdout", errno, 1));
		if (dup2(fd, STDOUT_FILENO) < 0)
			return (return_error("minishell", "stdout", errno, 1));
		close(fd);
	}
	return (0);
}

int	stdin_init(char *tty)
{
	int	fd;

	if (!isatty(STDIN_FILENO))
	{
		fd = open(tty, O_RDWR);
		if (fd < 0)
			return (return_error("minishell", "stdin", errno, 1));
		if (dup2(fd, STDIN_FILENO) < 0)
			return (return_error("minishell", "stdin", errno, 1));
		close(fd);
	}
	return (0);
}

int	stderr_init(char *tty)
{
	int	fd;

	if (!isatty(STDERR_FILENO))
	{
		fd = open(tty, O_RDWR);
		if (fd < 0)
			return (return_error("minishell", "stderr", errno, 1));
		if (dup2(fd, STDERR_FILENO) < 0)
			return (return_error("minishell", "stderr", errno, 1));
		close(fd);
	}
	return (0);
}
