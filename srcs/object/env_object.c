/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addenv_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:59:08 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/29 15:59:13 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

/*
** set 생성 후 마지막 원소 뒤에 붙여주기
*/

int	env_oadd(t_list *list)
{
	t_env	*env;
	t_env	*temp;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (error_list_free("Error : failed malloc\n", list));
	env->name = 0;
	env->s = 0;
	env->next = 0;
	temp = env_olast(list);
	if (!temp)
		list->env = env;
	else
		temp->next = env;
	return (1);
}

/*
** set의 마지막 원소 찾기
*/

t_env	*env_olast(t_list *list)
{
	t_env		*temp;

	temp = list->env;
	if (!temp)
		return (temp);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

/*
** set의 원소 찾기
*/

t_env	*find_env(t_list *list, char *s)
{
	t_env	*temp;

	temp = list->env;
	while (temp)
	{
		if (!ft_strcmp(temp->name, s))
			return (temp);
		temp = temp->next;
	}
	return (0);
}

static t_env	*remove_env_check_name(t_list *list, t_env **temp,
			t_env **before, char *s)
{
	t_env	*temp2;

	if (!ft_strcmp(s, (*temp)->name))
	{
		temp2 = (*temp)->next;
		if (*before)
			(*before)->next = (*temp)->next;
		else
			list->env = (*temp)->next;
		free((*temp)->name);
		free((*temp)->s);
		free(*temp);
		*temp = 0;
		return (temp2);
	}
	else
		return (0);
}

/*
** set의 원소 지우기
*/

void	remove_env(t_list *list, char *s)
{
	t_env	*temp;
	t_env	*temp2;
	t_env	*before;

	temp = list->env;
	before = 0;
	while (temp)
	{
		temp2 = remove_env_check_name(list, &temp, &before, s);
		if (!temp)
		{
			if (before)
				before->next = temp2;
			else
				list->env = temp;
			return ;
		}
		before = temp;
		temp = temp->next;
	}
}
