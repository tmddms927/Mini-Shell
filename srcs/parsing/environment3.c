/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:44:57 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/29 17:06:59 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	set_path(t_list *list)
{
	t_env	*temp;

	temp = list->env;
	while (temp)
	{
		if (temp->s[0] == 'P' && temp->s[1] == 'A'
			&& temp->s[2] == 'T' && temp->s[3] == 'H')
			list->path = ft_split_envp(temp->s);
		temp = temp->next;
	}
	return (1);
}
