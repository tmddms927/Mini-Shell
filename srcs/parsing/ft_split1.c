/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 03:04:25 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/25 21:04:22 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "split.h"

int	put_words3(t_pars *pars, char **s, t_list *list)
{
	if (**s == '$' && pars->type != 2)
	{
		if (!variable_in_set(pars, list, s))
			return (0);
	}
	if (pars->type % 10 == 0 && **s == '"')
	{
		pars->i++;
		pars->type = 1;
		**s = 0;
		return (1);
	}
	else if (pars->type % 10 == 0 && **s == '\'')
	{
		pars->i++;
		pars->type = 2;
		**s = 0;
		return (1);
	}
	return (2);
}

static int	put_words2_2(t_pars *pars, char **s)
{
	int			val;

	val = put_words5(pars, s);
	if (val == 2)
	{
		val = put_words6(pars, s);
		if (val == 2)
		{
			val = put_words7(pars, *s);
			if (val == 2)
				put_words8(pars, *s);
		}
		else if (!val)
			return (0);
	}
	else if (!val)
		return (0);
	return (1);
}

static int	put_words2_1(t_pars *pars, char **s, t_list *list)
{
	int			val;

	val = put_words3(pars, s, list);
	if (val == 2)
	{
		val = put_words4(pars, *s);
		if (val == 2)
		{
			if (!put_words2_2(pars, s))
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

static int	put_words(t_words *words, char *s, t_list *list, t_pars	*pars)
{
	while (*s)
	{
		if (!put_words2_1(pars, &s, list))
			return (0);
		s++;
		pars->pos++;
	}
	if (pars->i > 0 && (pars->type == 1 || pars->type == 2))
		return (free_words(words, "Error : unclosed quotes\n"));
	if (pars->i > 0)
	{
		if (!input_words(words, s - pars->i, pars->i, pars->type))
			return (free_words(words, ""));
	}
	free(pars->orig_s);
	return (1);
}

/*
** split main function
*/

int	ft_split(t_words *words, char *s, t_list *list)
{	
	t_pars	*pars;
	
	if (!s)
		return (free_words(words, ""));
	pars = (t_pars *)malloc(sizeof(t_pars));
	if (!pars)
		return (error_print("Error : failed malloc\n"));
	pars->type = 0;
	pars->i = 0;
	pars->orig_s = s;
	pars->orig_len = ft_strlen(s);
	pars->words = words;
	pars->pos = 0;
	if (!put_words(words, s, list, pars))
	{
		free(pars);
		return (0);
	}
	free(pars);
	return (1);
}
