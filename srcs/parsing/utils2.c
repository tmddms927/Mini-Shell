/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 00:27:19 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/13 08:07:03 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			free_list(t_list *list, char *s)
{
	int		i;

	i = 0;
	printf("%s", s);
	if (list->path)
	{
		while (list->path[i])
		{
			free(list->path[i]);
			i++;
		}
		free(list->path);
	}
	return (0);
}

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
