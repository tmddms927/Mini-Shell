/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 07:14:12 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/07 07:19:51 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int					oadd(t_list *list)
{
	t_com			*temp;
	t_com			*com;
	
	com = (t_com *)malloc(sizeof(t_com));
	if (!com)
		return (error_free("Error : failed malloc\n", list));
	com->c = 0;
	com->argv = 0;
	com->next = 0;
	com->path = 0;
	com->re_head = 0;
	if (!list->head)
	{
		list->head = com;
		return (1);
	}
	temp = list->head;
	while (temp)
		temp = temp->next;
	temp = com;
	return (1);
}

t_com			*olast(t_list *list)
{
	t_com		*temp;

	temp = list->head;
	if (!temp)
		return (temp);
	printf("hi1\n");
	while (temp->next)
		temp = temp->next;
	printf("hi2\n");
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