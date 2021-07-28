/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 21:19:57 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/28 21:19:58 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
