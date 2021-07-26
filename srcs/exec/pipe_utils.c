#include "exec.h"
#include <errno.h>

int	to_pipe(int *pipefd)
{
	if (pipefd)
	{
		close(pipefd[READ]);
		if (dup2(pipefd[WRITE], STDOUT_FILENO) < 0)
			return (return_error("minishell", "pipe", errno, 1));
		close(pipefd[WRITE]);
	}
	return (0);
}

int	from_pipe(int *pipefd)
{
	if (pipefd)
	{
		close(pipefd[WRITE]);
		if (dup2(pipefd[READ], STDIN_FILENO) < 0)
			return (return_error("minishell", "pipe", errno, 1));
		close(pipefd[READ]);
	}
	return (0);
}
