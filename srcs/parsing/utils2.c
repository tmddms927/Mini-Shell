/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 00:27:19 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/23 14:32:12 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	free_list(t_list *list, char *s)
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
