/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_object.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:54:35 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/21 16:29:36 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

/*
** re 생성 후 마지막 원소 뒤에 붙여주기
*/

int	re_odd(t_list *list)
{
	t_com			*com;
	t_re			*temp;
	t_re			*re;

	re = (t_re *)malloc(sizeof(t_re));
	if (!re)
		return (error_list_free("Error : failed malloc\n", list));
	re->next = 0;
	re->type = NOT;
	re->file = 0;
	com = com_olast(list);
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

/*
** re의 마지막 원소 찾기
*/

t_re	*re_olast(t_list *list)
{
	t_com			*com;
	t_re			*temp;

	com = com_olast(list);
	temp = com->re_head;
	if (!temp)
		return (temp);
	while (temp->next)
		temp = temp->next;
	return (temp);
}
