/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 03:04:25 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/21 18:31:45 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "split.h"


/*
** 0 = X, 1 = ", 2 = '
*/

static int	put_words(t_words *words, char *s)
{
	int			type;
	int			i;
	int			val;

	type = 0;
	i = 0;
	while (*s)
	{
		if (!put_words2(words, s, &type, &i))
			return (0);
		s++;
	}
	if (i > 0 && (type == 1 || type == 2))
		return (free_words(words, "Error : unclosed quotes\n"));
	if (i > 0)
	{
		if (!input_words(words, s - i, i, type))
			return (free_words(words, ""));
	}
	return (1);
}

/*
** split main function
*/

int			ft_split(t_words *words, char *s)
{	
	if (!s)
		return (free_words(words, ""));
	if (!put_words(words, s))
		return (0);
	return (1);
}

///////////////////////////////////////////////////
void		print_word(t_words *words)
{
	t_word	*temp;

	temp = words->head;
	while (temp)
	{
		printf("%d, %s\n", temp->type, temp->s);
		temp = temp->next;
	}
}
