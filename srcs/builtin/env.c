/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 22:07:52 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/29 16:11:09 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	env(t_list *list)
{
	t_env	*temp;

	temp = list->env;
	while (temp)
	{
		printf("%s\n", temp->s);
		temp = temp->next;
	}
	return (0);
}
