/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:43:48 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/07 07:14:23 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				error_free(char *s, t_list *list)
{
	t_com			*temp;
	t_com			*next;
	
	printf("%s\n", s);
	temp = list->head;
	next = list->head;
	while (next)
	{
		next = temp->next;
		free(temp);
	}
	list->head = 0;
	return (0);
}

size_t			ft_strlen(char *s)
{
	int			i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char			*ft_strcat(char *s1, char s2)
{
	size_t		len1;
	size_t		i;
	char		*temp;

	i = 0;
	len1 = ft_strlen(s1);
	temp = (char *)malloc(sizeof(char) * (len1 + 2));
	if (!temp)
		return (0);
	while (i < len1)
		temp[i] = s1[i++];
	temp[i++] = s2;
	temp[i] = 0;
	if (s1)
		free(s1);
	return (temp);
}