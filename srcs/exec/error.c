/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 21:19:47 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/30 16:05:37 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include "object.h"

void	print_err(char *s1, char *s2, char *s3)
{
	write(2, s1, ft_strlen(s1));
	write(2, ": ", 2);
	write(2, s2, ft_strlen(s2));
	write(2, ": ", 2);
	write(2, s3, ft_strlen(s3));
	write(2, "\n", 1);
}

void	snatch_error(int error_num, t_list *command_list)
{
	int		i;
	char	s[3];
	int		j;
	t_set	*temp;

	temp = find_set(command_list, "?\0");
	i = -1;
	j = 0;
	if (error_num == 0)
		temp->value[++i] = '0';
	while (error_num > 0)
	{
		s[j++] = error_num % 10 + '0';
		error_num = error_num / 10;
	}
	while (++i < j)
		temp->value[i] = s[j - i - 1];
	while (i < 3)
		temp->value[i++] = 0;
}

void	exit_safe(char *func_name, char *obj, int err_num, int exit_num)
{
	if (err_num < 108)
		print_err(func_name, obj, strerror(err_num));
	else if (err_num == 127)
		command_not_found(func_name, obj);
	exit(exit_num);
}

int	return_error(char *func_name, char *obj, int err_num, int exit_num)
{
	if (err_num < 108)
		print_err(func_name, obj, strerror(err_num));
	else if (err_num == 127)
		command_not_found(func_name, obj);
	return (exit_num);
}

void	command_not_found(char *func_name, char *obj)
{
	write(2, func_name, ft_strlen(func_name));
	write(2, ": ", 2);
	write(2, obj, ft_strlen(obj));
	write(2, ": ", 2);
	write(2, "command not found\n", 18);
}
