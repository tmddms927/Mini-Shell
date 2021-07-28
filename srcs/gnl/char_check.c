/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:58:15 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/28 20:12:57 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "header.h"
#include "object.h"

static int	down(int *idx, char **s, t_list *list)
{
	while (--*idx >= 0)
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
	if (c == 4479771 || c == 4414235 || c == -314287333 || c == -314352869)
		return (1);
	if (c == 4283163 || c == -314483941)
	{
		while (--*idx >= 0)
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
		down(idx, s, list);
	return (1);
}

static int	buf_check2(int c, int *idx, char **s, t_list *list)
{
	if (c == 4283163 || c == 4348699 || c == 4479771 || c == 4414235)
		return (up_down(c, idx, s, list));
	return (0);
}

int	buf_check(int c, int *idx, char **s, t_list *list)
{
	if ((c == 4) && !*idx)
	{
		write(0, "exit\n", 5);
		return (0);
	}
	else if (c == 127)
	{
		if (*idx > 0)
		{
			write(0, "\b \b", 3);
			(*idx)--;
			(*s)[*idx] = 0;
		}
	}
	else if (buf_check2(c, idx, s, list))
		return (2);
	else
	{
		write(0, &c, 1);
		(*idx)++;
	}
	return (1);
}
