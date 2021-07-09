/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 07:14:12 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/09 01:21:39 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int					oadd(t_list *list)
{
	t_com			*temp;
	t_com			*com;
	
	com = (t_com *)malloc(sizeof(t_com));
	if (!com)
		return (error_list_free("Error : failed malloc\n", list));
	com->c = 0;
	com->argv = (char **)malloc(sizeof(char *));
	if (!com->argv)
		return (error_list_free("Error : failed malloc\n", list));
	*com->argv = 0;
	com->next = 0;
	com->path = 0;
	com->re_head = 0;
	com->type = COM;
	if (!list->head)
	{
		list->head = com;
		return (1);
	}
	temp = list->head;
	if (!temp)
		temp = com;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = com;
	}
	return (1);
}

int				re_odd(t_list *list)
{
	t_com		*com;
	t_re		*temp;
	t_re		*re;

	re = (t_re *)malloc(sizeof(t_re));
	if (!re)
		return (error_list_free("Error : failed malloc\n", list));
	re->next = 0;
	re->type = NOT;
	re->file = 0;
	com = olast(list);
	temp = com->re_head;
	if (!temp)
		com->re_head = re;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = re;
	}
	return (1);
}

t_com			*olast(t_list *list)
{
	t_com		*temp;

	temp = list->head;
	if (!temp)
		return (temp);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_re			*re_olast(t_list *list)
{
	t_com		*com;
	t_re		*temp;

	com = olast(list);
	temp = com->re_head;
	if (!temp)
		return (temp);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_list			*init_list(void)
{
	t_list		*temp;

	temp = (t_list *)malloc(sizeof(t_list) * 1);
	if (!temp)
		return (temp);
	temp->head = 0;
	return(temp);
}
