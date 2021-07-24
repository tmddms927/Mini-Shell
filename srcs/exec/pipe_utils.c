#include "exec.h"
#include <errno.h>

void	to_pipe(int *pipefd)
{
	if (pipefd)
	{
		close(pipefd[READ]);
		if (dup2(pipefd[WRITE], STDOUT_FILENO) < 0)
			exit_safe("minishell", "pipe", errno, 1);
		close(pipefd[WRITE]);
	}
}

void	from_pipe(int *pipefd)
{
	if (pipefd)
	{
		close(pipefd[WRITE]);
		if (dup2(pipefd[READ], STDIN_FILENO) < 0)
			exit_safe("minishell", "pipe", errno, 1);
		close(pipefd[READ]);
	}
}
