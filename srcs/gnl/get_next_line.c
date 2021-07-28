/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:03:43 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/28 15:56:09 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *g_backup[OPEN_MAX];

void	ctrl_c(int signo)
{
	(void)signo;

	free(g_backup[0]);
	g_backup[0] = 0;
	write(1, "\nprompt > ", 10);
	return ;
}

int				get_next_line(int fd, char **line, t_list *list)
{
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	int			end_index;
	int			idx;
	int			ch;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	idx = 0;
	while ((read_size = read(fd, &ch, sizeof(ch))) > 0)
	{
		if (!buf_check(ch, &idx, &g_backup[fd], list))
			continue ;
		buf[0] = ch;
		buf[read_size] = 0;
		g_backup[fd] = gnl_ft_strjoin(g_backup[fd], buf);
		if ((end_index = check_line(g_backup[fd])) > -1)
			return (split_line(&g_backup[fd], line, end_index));
	}
	return (check_return(&g_backup[fd], line, read_size));
}

int				check_line(char *g_backup)
{
	int			i;

	i = 0;
	while (g_backup[i])
	{
		if (g_backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int				split_line(char **g_backup, char **line, int end_index)
{
	int			i;

	i = -1;
	if (!(*line = (char *)malloc(sizeof(char) * (end_index + 1))))
		return (-1);
	while (++i < end_index)
		(*line)[i] = (*g_backup)[i];
	(*line)[i] = 0;
	i = 0;
	end_index++;
	while ((*g_backup)[end_index])
		(*g_backup)[i++] = (*g_backup)[end_index++];
	(*g_backup)[i] = 0;
	return (1);
}

int				check_return(char **g_backup, char **line, int read_size)
{
	int			end_index;

	if (read_size < 0)
		return (-1);
	else if (*g_backup && (end_index = check_line(*g_backup)) > -1)
		return (split_line(g_backup, line, end_index));
	else if (*g_backup)
	{
		*line = *g_backup;
		*g_backup = 0;
		return (0);
	}
	if (!(*line = (char *)malloc(sizeof(char) * 1)))
		return (-1);
	**line = 0;
	return (0);
}