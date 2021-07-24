/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 03:04:25 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/24 21:26:52 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "split.h"

int	put_words3(char *s, int *type, int *i)
{
	if (*s == '$' && *type != 2)
	{
		variable_in_set(&s, );
		*s = '!';
	}
	if (*type % 10 == 0 && *s == '"')
	{
		(*i)++;
		*type = 1;
		*s = 0;
		return (1);
	}
	else if (*type % 10 == 0 && *s == '\'')
	{
		(*i)++;
		*type = 2;
		*s = 0;
		return (1);
	}
	return (2);
}

static int	put_words2_2(t_words *words, char **s, int *type, int *i)
{
	int			val;

	val = put_words5(words, s, type, i);
	if (val == 2)
	{
		val = put_words6(words, s, type, i);
		if (val == 2)
		{
			val = put_words7(words, *s, type, i);
			if (val == 2)
				put_words8(*s, type, i);
		}
		else if (!val)
			return (0);
	}
	else if (!val)
		return (0);
	return (1);
}

static int	put_words2_1(t_words *words, char **s, int *type, int *i)
{
	int			val;

	val = put_words3(*s, type, i);
	if (val == 2)
	{
		val = put_words4(words, *s, type, i);
		if (val == 2)
		{
			if (!put_words2_2(words, s, type, i))
				return (0);
		}
		else if (!val)
			return (0);
	}
	else if (!val)
		return (0);
	return (1);
}

/*
** 0 = X, 1 = ", 2 = '
*/

static int	put_words(t_words *words, char *s)
{
	// int			type;
	// int			i;

	// type = 0;
	// i = 0;
	t_pars	*pars;
	
	pars = (t_pars *)malloc(sizeof(t_pars));
	if (!pars)
		return (error_print("Error : failed malloc\n"));
	pars->type = 0;
	pars->i = 0;
	pars->orig_s = s;
	while (*s)
	{
		if (!put_words2_1(words, &s, &type, &i))
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

int	ft_split(t_words *words, char *s)
{	
	if (!s)
		return (free_words(words, ""));
	if (!put_words(words, s))
		return (0);

	
	
	// t_word *temp;
	// temp = words->head;
	// while (temp)
	// {
	// 	printf("%d, %s\n", temp->type, temp->s);
	// 	temp = temp->next;
	// }


	
	return (1);
}
