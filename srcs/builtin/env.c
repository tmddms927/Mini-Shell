/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwan <hwan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 22:07:52 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/27 16:56:20 by hwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	env(t_list *list)
{
	int			i;
	t_addenv	*temp;

	i = -1;
	while (list->envp[++i])
		printf("%s\n", list->envp[i]);
	temp = list->addenv;
	while (temp)
	{
		printf("%s\n", temp->s);
		temp = temp->next;
	}
	return (1);
}
