/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:38:27 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/25 22:25:16 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

/*
** set 생성 후 마지막 원소 뒤에 붙여주기
*/

int	set_oadd(t_list *list)
{
	t_set		*set;
	t_set		*temp;

	set = (t_set *)malloc(sizeof(t_set));
	if (!set)
		return (error_list_free("Error : failed malloc\n", list));
	set->name = 0;
	set->value = 0;
	set->next = 0;
	temp = set_olast(list);
	if (!temp)
		list->set = set;
	else
		temp->next = set;
	return (1);
}

/*
** set의 마지막 원소 찾기
*/

t_set	*set_olast(t_list *list)
{
	t_set		*temp;

	temp = list->set;
	if (!temp)
		return (temp);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

/*
** set의 $? 원소 찾기
*/

t_set	*find_set(t_list *list, char *s)
{
	t_set		*temp;

	temp = list->set;
	while (temp)
	{
		if (!ft_strcmp(temp->name, s))
			return (temp);
		temp = temp->next;
	}
	return (temp);
}
