/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:03:43 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/30 17:36:40 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*g_backup[OPEN_MAX];

void	ctrl_c_non(int signo)
{
	(void)signo;
	free(g_backup[0]);
	g_backup[0] = 0;
	write(1, "\nprompt > ", 10);
	return ;
}

int	get_next_line(int fd, char **line, t_list *list, int check)
{
	char		buf[BUFFER_SIZE + 1];
	int			end_index;
	int			idx;
	int			c;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	idx = 0;
	c = 0;
	while (read(fd, &c, BUFFER_SIZE))
	{
		check = buf_check(&c, &idx, &g_backup[fd], list);
		if (check == 2)
			continue ;
		else if (check == 0)
			return (0);
		buf[0] = c;
		buf[1] = 0;
		g_backup[fd] = gnl_ft_strjoin(g_backup[fd], buf);
		end_index = check_line(g_backup[fd], &end_index);
		if (end_index > -1)
			return (split_line(&g_backup[fd], line, end_index));
		c = 0;
	}
	return (check_return(&g_backup[fd], line, 1));
}

int	check_line(char *g_backup, int *end_index)
{
	int			i;

	i = 0;
	while (g_backup[i])
	{
		if (g_backup[i] == '\n')
		{
			*end_index = i;
			return (i);
		}
		i++;
	}
	*end_index = -1;
	return (-1);
}

int	split_line(char **g_backup, char **line, int end_index)
{
	int			i;

	i = -1;
	*line = (char *)malloc(sizeof(char) * (end_index + 1));
	if (!*line)
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

int	check_return(char **g_backup, char **line, int read_size)
{
	int			end_index;

	if (read_size < 0)
		return (-1);
	else if (*g_backup && check_line(*g_backup, &end_index) && end_index > -1)
		return (split_line(g_backup, line, end_index));
	else if (*g_backup)
	{
		*line = *g_backup;
		*g_backup = 0;
		return (0);
	}
	*line = (char *)malloc(sizeof(char) * 1);
	if (!*line)
		return (-1);
	**line = 0;
	return (0);
}
