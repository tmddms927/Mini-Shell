/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:48:51 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/21 16:29:17 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

/*
** com 생성 후 마지막 원소 뒤에 붙여주기
*/

int	com_oadd(t_list *list)
{
	t_com			*temp;
	t_com			*com;

	com = com_oadd2();
	if (!com)
		return (error_list_free("Error : failed malloc\n", list));
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

t_com	*com_oadd2(void)
{
	t_com			*com;

	com = (t_com *)malloc(sizeof(t_com));
	if (!com)
		return (0);
	com->c = 0;
	com->argv = (char **)malloc(sizeof(char *));
	if (!com->argv)
		return (0);
	*com->argv = 0;
	com->next = 0;
	com->path = 0;
	com->re_head = 0;
	com->type = COM;
	return (com);
}

/*
** com의 마지막 원소 찾기
*/

t_com	*com_olast(t_list *list)
{
	t_com			*temp;

	temp = list->head;
	if (!temp)
		return (temp);
	while (temp->next)
		temp = temp->next;
	return (temp);
}
