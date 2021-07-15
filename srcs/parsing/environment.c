/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 23:44:48 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/14 01:38:28 by seungoh          ###   ########.fr       */
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

// int			set_environment(t_list *list, t_words *words)
// {
// 	int		i;
// 	t_word	*temp;

// 	temp = words->head;
// 	while (temp)
// 	{
// 		if ((temp->type == 1 || temp->type == 10) &&
// 			temp->s[0] == '$')
// 		temp = temp->next;
// 	}
// }
