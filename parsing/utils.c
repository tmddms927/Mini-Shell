/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:43:48 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/07 05:35:31 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int					oadd(t_list list)
{
	t_com			*temp;
	t_com			*com;
	
	com = (t_com *)malloc(sizeof(t_com));
	if (!com)
		return (error_free("Error : failed malloc\n", list));
	if (!list.head)
	{
		list.head = com;
		return (1);
	}
	temp = list.head;
	while (temp)
		temp = temp->next;
	temp = com;
}

int				error_free(char *s, t_list list)
{
	t_com			*temp;
	t_com			*next;
	
	printf("%s\n", s);
	temp = list.head;
	next = list.head;
	while (next)
	{
		next = temp->next;
		free(temp);
	}
	list.head = 0;
	return (0);
}
