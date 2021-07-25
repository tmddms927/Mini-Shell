#include "exec.h"
#include <stdio.h>
#include <errno.h>

void	separate_stream(int (*fp)(t_com *, char **), t_list *command_list)
{
	int	pid;
	int	ret;
	int	statloc;

	//command list vailiad test
	pid = fork();
	if (pid < CHILD)
		handle_error("minishell: separate_stream: fork error");
	else if (pid == CHILD)
	{
		ret = fp(command_list->head, command_list->envp);
		exit(ret);
	}
	waitpid(pid, &statloc, 0);
	snatch_error(WEXITSTATUS(statloc), command_list);
}

int	exec(t_com *command_info, char **envp)
{
	t_com	*c_list;
	int		pipefd[2];
	int		statloc;

	c_list = command_info;
	while (c_list)
	{
		if (c_list->next == 0)
			statloc = exec_to(NULL, c_list, envp);
		else
			statloc = exec_to(pipefd, c_list, envp);
		c_list = c_list->next;
	}
	return (statloc);
}

void	command(t_com *command_node, char **envp)
{
	int	i;

	i = 0;
	redirect(command_node->re_head);
	if (command_node->c)
	{
		while ((command_node->path)[i] != 0)
		{
			execve(command_node->path[i], command_node->argv, envp);
			i++;
		}
		exit_safe("minishell", command_node->argv[0], 127, 127);
	}
}

int	exec_to(int *to, t_com *command_node, char **envp)
{
	int		pid;
	int		statloc;

	if (to)
		pipe(to);
	pid = fork();
	if (pid < 0)
		handle_error("minishell: exec_to: fork error");
	else if (pid == CHILD)
	{
		to_pipe(to);
		command(command_node, envp);
	}
	waitpid(pid, &statloc, 0);
	from_pipe(to);
	return (WEXITSTATUS(statloc));
}
