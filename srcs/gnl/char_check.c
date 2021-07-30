/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:58:15 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/30 17:22:20 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "header.h"
#include "object.h"

int	g_i;
int	g_len;

static int	down(int *idx, char **s, t_list *list, int c)
{
	if (c == 4479771 || c == 4414235)
		return (1);
	g_i = -1;
	g_len = ft_strlen(*s);
	while (++g_i < g_len)
		write(0, "\b \b", 3);
	free(*s);
	*s = 0;
	if (list->his_check == 2)
		list->his_here = list->his->head;
	if (list->his_here && list->his_here->next)
	{
		if (list->his_check != 2)
			list->his_here = list->his_here->next;
		write(0, list->his_here->s, ft_strlen(list->his_here->s));
		*idx = ft_strlen(list->his_here->s);
		ft_strcat_s(s, &(list->his_here->s));
		if (!list->his_here->next)
			list->his_check = 1;
		else
			list->his_check = 0;
	}
	return (1);
}

static int	up_down(int c, int *idx, char **s, t_list *list)
{
	if (c == 4283163)
	{
		g_i = -1;
		g_len = ft_strlen(*s);
		while (++g_i < g_len)
			write(0, "\b \b", 3);
		free(*s);
		*s = 0;
		if (list->his_here && list->his_check == 1)
			list->his_here = his_olast(list);
		if (list->his_here)
		{
			write(0, list->his_here->s, ft_strlen(list->his_here->s));
			ft_strcat_s(s, &(list->his_here->s));
			*idx = ft_strlen(list->his_here->s);
			list->his_here = list->his_here->before;
			if (!list->his_here)
				list->his_check = 2;
			else
				list->his_check = 0;
		}
	}
	else
		down(idx, s, list, c);
	return (1);
}

static int	buf_check2(int c, int *idx, char **s, t_list *list)
{
	if (c == 4283163 || c == 4348699 || c == 4479771 || c == 4414235)
		return (up_down(c, idx, s, list));
	return (0);
}

int	buf_check(int *c, int *idx, char **s, t_list *list)
{
	if (*c == 4 && !*idx)
	{
		printf("exit\n");
		reset_input_mode(list);
		return (0);
	}
	else if (*c == 4)
		return (2);
	else if (*c == 127)
	{
		if (*idx > 0)
		{
			write(0, "\b \b", 3);
			if (s && *s)
				(*s)[--(*idx)] = 0;
			*c = 0;
		}
		return (2);
	}
	else if (buf_check2(*c, idx, s, list))
		return (2);
	write(0, c, 1);
	(*idx)++;
	return (1);
}
