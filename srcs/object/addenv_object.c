/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addenv_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:52:10 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/26 17:41:05 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

/*
** set 생성 후 마지막 원소 뒤에 붙여주기
*/

int	addenv_oadd(t_list *list)
{
	t_addenv	*addenv;
	t_addenv	*temp;

	addenv = (t_addenv *)malloc(sizeof(t_addenv));
	if (!addenv)
		return (error_list_free("Error : failed malloc\n", list));
	addenv->name = 0;
	addenv->s = 0;
	addenv->next = 0;
	temp = addenv_olast(list);
	if (!temp)
		list->addenv = addenv;
	else
		temp->next = addenv;
	return (1);
}

/*
** set의 마지막 원소 찾기
*/

t_addenv	*addenv_olast(t_list *list)
{
	t_addenv		*temp;

	temp = list->addenv;
	if (!temp)
		return (temp);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

/*
** set의 원소 찾기
*/

t_addenv	*find_addenv(t_list *list, char *s)
{
	t_addenv	*temp;

	temp = list->addenv;
	while (temp)
	{
		if (!ft_strcmp(temp->name, s))
			return (temp);
		temp = temp->next;
	}
	return (0);
}

static t_addenv	*remove_addenv_check_name(t_list *list, t_addenv **temp,
			t_addenv **before, char *s)
{
	t_addenv	*temp2;

	if (!ft_strcmp(s, (*temp)->name))
	{
		temp2 = (*temp)->next;
		if (*before)
			(*before)->next = (*temp)->next;
		else
			list->addenv = (*temp)->next;
		free((*temp)->name);
		free((*temp)->s);
		free(*temp);
		return (temp2);
	}
	else
		return (0);
}

/*
** set의 원소 지우기
*/

void	remove_addenv(t_list *list, char *s)
{
	t_addenv	*temp;
	t_addenv	*temp2;
	t_addenv	*before;

	temp = list->addenv;
	before = 0;
	while (temp)
	{
		temp2 = remove_addenv_check_name(list, &temp, &before, s);
		if (!temp2)
		{
			before = temp;
			temp = temp->next;
		}
		else
			temp = temp2;
	}
}