/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 23:44:48 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/29 16:27:21 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	set_path(t_list *list)
{
	t_env	*temp;

	temp = list->env;
	while (temp)
	{
		if (temp->s[0] == 'P' && temp->s[1] == 'A' &&
			temp->s[2] == 'T' && temp->s[3] == 'H')
			list->path = ft_split_envp(temp->s);
		temp = temp->next;
	}
	return (1);
}

/*
** path가 없을 경우
*/

static int	set_not_path_in_com(t_list *list)
{
	t_com	*temp;

	temp = list->head;
	while (temp)
	{
		temp->path = (char **)malloc(sizeof(char *) * 2);
		temp->path[0] = 0;
		if (!ft_strcat_s(temp->path, &temp->c))
			return (error_list_free("Error : failed malloc\n", list));
		temp->path[1] = 0;
		temp = temp->next;
	}
	return (1);
}

/*
** command에 path 붙여주기
*/

int	set_path_in_com(t_list *list)
{
	int		count;
	t_com	*temp;
	int		i;

	count = 0;
	if (!list->path)
		return (set_not_path_in_com(list));
	while (list->path[count])
		count++;
	temp = list->head;
	while (temp)
	{
		i = -1;
		temp->path = (char **)malloc(sizeof(char *) * (count + 1));
		if (!temp->path)
			return (0);
		while (++i < count)
			set_path_in_com2(temp, i, list);
		temp->path[i] = 0;
		temp = temp->next;
	}
	return (1);
}

int	set_path_in_com2(t_com *temp, int i, t_list *list)
{
	temp->path[i] = 0;
	if (!ft_strcat_s(&temp->path[i], &list->path[i]))
		return (error_list_free("Error : failed malloc\n", list));
	if (!ft_strcat_s(&temp->path[i], &temp->c))
		return (error_list_free("Error : failed malloc\n", list));
	return (1);
}

/*
** path free
*/

void	free_path(t_list *list)
{
	int	i;

	i = -1;
	if (!list->path)
		return ;
	while (list->path[++i])
	{
		free(list->path[i]);
	}
	free(list->path);
	list->path = 0;
}
