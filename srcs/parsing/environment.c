/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 23:44:48 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/21 16:09:09 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			set_path(t_list *list, char **envp)
{
	int		i;

	i = -1;
	if (!envp)
		return (0);
	while (envp[++i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A' &&
			envp[i][2] == 'T' && envp[i][3] == 'H')
			list->path = ft_split_envp(envp[i]);
	}
	return (1);
}


/*
** command에 path 붙여주기
*/

int			set_path_in_com(t_list *list)
{
	int		count;
	t_com	*temp;
	int		i;

	count = 0;
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
		{
			temp->path[i] = 0;
			if (!ft_strcat_s(&temp->path[i], &list->path[i]))
				return (error_list_free("Error : failed malloc\n", list));
			if (!ft_strcat_s(&temp->path[i], &temp->c))
				return (error_list_free("Error : failed malloc\n", list));
		}
		temp->path[i] = 0;
		temp = temp->next;
	}
	return (1);
}
