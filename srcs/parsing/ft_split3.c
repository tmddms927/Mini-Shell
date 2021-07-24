/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 04:39:43 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/24 23:50:05 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "object.h"

int	input_words(t_words *words, char *s, int len, int type)
{
	t_word		*temp;
	int			i;
	int			j;

	if (!words_oadd(words))
		return (free_words(words, "Error : failed malloc\n"));
	temp = words_olast(words);
	if (type == 10)
		temp->type = 1;
	else if (type == 20)
		temp->type = 2;
	else
		temp->type = type;
	temp->s = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp->s)
		return (free_words(words, "Error : failed malloc\n"));
	i = -1;
	j = 0;
	while (++i < len)
	{
		if (s[i])
			temp->s[j++] = s[i];
	}
	temp->s[j] = 0;
	return (1);
}
