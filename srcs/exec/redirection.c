/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwan <hwan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 21:19:59 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/30 17:34:18 by hwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int	redirect(char *tty, t_re *redir_list)
{
	int		ret;
	t_re	*re;

	ret = 0;
	re = redir_list;
	while (re)
	{
		if (re->type == H_DOC)
			ret = h_doc(tty, re->file);
		re = re->next;
	}
	re = redir_list;
	while (!ret && re)
	{
		if (re->type == RE_OUT)
			ret = re_out(re->file);
		else if (re->type == RE_IN)
			ret = re_in(re->file);
		else if (re->type == APPEND)
			ret = append(re->file);
		re = re->next;
	}
	return (ret);
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
