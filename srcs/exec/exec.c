/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwan <hwan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 21:19:51 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/30 15:59:31 by hwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

int	exec(t_list *list)
{
	t_com	*c;
	int		pipefd[2];
	int		statloc;
	int		s;

	c = list->head;
	while (c)
	{
		if (c->next == 0)
			statloc = exec_to(list, c, NULL);
		else
			statloc = exec_to(list, c, pipefd);
		c = c->next;
	}
	while (wait(&s) != -1)
		;
	stdio_init(list->tty);
	return (statloc);
}

int	command(t_list *list, t_com *com)
{
	int	i;
	int	ret;

	i = 0;
	ret = redirect(list->tty, com->re_head);
	if (ret)
		return (ret);
	ret = do_builtin(list, com);
	if (ret >= 0)
		return (ret);
	return (do_non_builtin(list, com));
}

int	exec_to(t_list *list, t_com *com, int *to)
{
	int	pid;
	int	statloc;

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
		waitpid(pid, &statloc, WNOWAIT);
		if (from_pipe(to))
			return (1);
		return (WEXITSTATUS(statloc));
	}
	return (command(list, com));
}

int	do_non_builtin(t_list *list, t_com *com)
{
	int	i;
	int	pid;
	int	statloc;

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
		exit(0);
	}
	waitpid(pid, &statloc, 0);
	return (WEXITSTATUS(statloc));
}
