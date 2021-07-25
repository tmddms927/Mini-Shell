/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 21:54:13 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/25 22:22:26 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	sort_env(t_list *list)
{
	int		i;
	int		check;
	t_set	*temp;
	t_set	*front;
	t_set	*back;
	
	i = 0;
	check = 1;
	while (check)
	{
		i = 0;
		check = 0;
		front = list->set;
		back = front->next;
		temp = list->set;
		while (front && back)
		{
			if (ft_strcmp(front->name, back->name) > 0)
			{
				
				check = 1;
			}
			temp = front;
			front = back;
			back = back->next;
			i++;
		}
	}
}

void	export(t_list *list)
{
	int		i;
	t_set	*temp;

	sort_env(list);
	i = -1;
	temp = list->set;
	while (temp)
	{
		printf("declare -x ");
		printf("%s", temp->name);
		if (temp->value)
			printf("\"%s\"\n", temp->value);
		else
			printf("\n");
	}
}
