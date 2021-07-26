#include "exec.h"
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

// int	multy_command(t_list * list)
// {
// 	t_com	*c;
// 	int		ret;

// 	c = list->head;
// 	while (c)
// 	{
// 		if (c->next == 0)
// 			ret = command(list, c, FALSE);
// 		else
// 			ret = command(list, c, TRUE);
// 		c = c->next;
// 	}
// 	if (stdio_init(list->tty))
// 		return (1);
// 	return (ret);
// }


// int	command(t_list *list, t_com *com, t_bool next)
// {
// 	int pipefd[2];
// 	int ret;

// 	ret = 0;
// 	if (pipe(pipefd) < 0)
// 		return (return_error("minishell", "pipe", errno, 1));
// 	ret = redirect(list->tty, com->re_head);
// 	if (ret)
// 		return (ret);
// 	if (next)
// 	{
// 		ret = to_pipe(pipefd);
// 		if (ret)
// 			return (ret);
// 	}
// 	ret = do_builtin(list, com);
// 	if (ret >= 0)
// 		return (ret);
// 	ret = exec(com, pipefd, list->envp);
// 	return (ret);
// }

// int	exec(t_com *command_node, int *pipe, char **envp)
// {
// 	int	i;
// 	int	pid;
// 	int	statloc;
// 	int	ret;

// 	i = 0;
// 	pid = fork();
// 	if (pid < 0)
// 		return (return_error("minishell", "fork", errno, 1));
// 	if (pid == CHILD)
// 	{
// 		while (command_node->c && (command_node->path)[i] != 0)
// 		{
// 			execve(command_node->path[i], command_node->argv, envp);
// 			i++;
// 		}
// 		exit_safe("minishell", command_node->argv[0], 127, 127);
// 	}
// 	waitpid(pid, &statloc, 0);
// 	ret = from_pipe(pipe);
// 	if (ret)
// 		return (ret);
// 	return (WEXITSTATUS(statloc));
// }



// void	separate_stream(int (*fp)(t_com *, char **), t_list *command_list)
// {
// 	int	pid;
// 	int	ret;
// 	int	statloc;

// 	//command list vailiad test
// 	pid = fork();
// 	if (pid < CHILD)
// 		handle_error("minishell: separate_stream: fork error");
// 	else if (pid == CHILD)
// 	{
// 		ret = fp(command_list->head, command_list->envp);
// 		exit(ret);
// 	}
// 	waitpid(pid, &statloc, 0);
// 	snatch_error(WEXITSTATUS(statloc), command_list);
// }

int	exec(t_list *list)
{
	t_com	*c;
	int		pipefd[2];
	int		statloc;

	c = list->head;
	while (c)
	{
		if (c->next == 0)
			statloc = exec_to(list, c, NULL);
		else
			statloc = exec_to(list, c, pipefd);
		if (statloc)
		{
			stdio_init(list->tty);
			return (statloc);
		}
		c = c->next;
	}
	stdio_init(list->tty);
	return (statloc);
}

int	command(t_list *list, t_com *com)
{
	int	i;
	int ret;

	i = 0;
	ret = redirect(list->tty, com->re_head);
	if (ret)
		return (ret);
	ret = do_builtin(list, com);
	if (ret >= 0)
		return (ret);
	return (do_non_builtin(list, com));
}

int	exec_to(t_list * list, t_com *com, int *to)
{
	int		pid;
	int		statloc;

	if (to)
	{
		pipe(to);
		pid = fork();
		if (pid < 0)
			return (return_error("minishell", com->c, errno, 1));
		else if (pid == CHILD)
		{
			if (to_pipe(to))
				exit(1);
			exit(command(list, com));
		}
		waitpid(pid, &statloc, 0);
		if (from_pipe(to))
			return (1);
		return (WEXITSTATUS(statloc));
	}
	return (command(list, com));
}

int do_non_builtin(t_list *list, t_com *com)
{
	int	i;
	int pid;
	int statloc;

	i = 0;
	pid = fork();
	if (pid < 0)
		return (return_error("minishell", com->c, errno, 1));
	if (pid == CHILD)
	{
		if (com->c)
		{
			while ((com->path)[i] != 0)
			{
				execve(com->path[i], com->argv, list->envp);
				i++;
			}
			exit_safe("minishell", com->argv[0], 127, 127);
		}
	}
	waitpid(pid, &statloc, 0);
	return (WEXITSTATUS(statloc));
}