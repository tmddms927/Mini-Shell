/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 21:54:13 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/25 23:20:27 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	sort_env(t_list *list, int check)
{
	t_set	*front;
	t_set	*back;
	char	*temp1;
	char	*temp2;

	while (check)
	{
		check = 0;
		front = list->set;
		back = front->next;
		while (front && back)
		{
			if (ft_strcmp(front->name, back->name) > 0)
			{
				temp1 = front->name;
				temp2 = front->value;
				front->name = back->name;
				front->value = back->value;
				back->name = temp1;
				back->value = temp2;
				check = 1;
			}
			front = back;
			back = back->next;
		}
	}
}

int	export(t_list *list)
{
	t_set	*temp;
	
	sort_env(list, 1);
	temp = list->set;
	while (temp)
	{
		if (!ft_strcmp(temp->name, "?\0"))
		{
			temp = temp->next;
			continue ;
		}
		printf("declare -x ");
		printf("%s=", temp->name);
		if (temp->value[0])
			printf("\"%s\"\n", temp->value);
		else
			printf("\n");
		temp = temp->next;
	}
	return (1);
}
