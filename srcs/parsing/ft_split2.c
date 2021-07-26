/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:47:06 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/26 00:01:52 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "split.h"

int	put_words4(t_pars *pars, char *s)
{
	if (pars->type != 1 && pars->type != 2 && *s == '|')
	{
		if (pars->i > 0)
		{
			if (!input_words(pars->words, s - pars->i, pars->i, pars->type))
				return (free_words(pars->words, ""));
		}
		if (!input_words(pars->words, s, 1, pars->type))
			return (free_words(pars->words, ""));
		pars->i = 0;
		pars->type = 0;
		return (1);
	}
	return (2);
}

int	put_words5(t_pars *pars, char **s)
{
	if (pars->type != 1 && pars->type != 2 && **s == '>')
	{
		if (pars->i > 0)
		{
			if (!input_words(pars->words, *(s - pars->i), pars->i, pars->type))
				return (free_words(pars->words, ""));
		}
		if (*s + 1 && *((*s) + 1) == '>')
		{
			if (!input_words(pars->words, *s, 2, pars->type))
				return (free_words(pars->words, ""));
			(*s)++;
			pars->pos++;
		}
		else
		{
			if (!input_words(pars->words, *s, 1, pars->type))
				return (free_words(pars->words, ""));
		}
		pars->i = 0;
		pars->type = 0;
		return (1);
	}
	return (2);
}

int	put_words6(t_pars *pars, char **s)
{
	if (pars->type != 1 && pars->type != 2 && **s == '<')
	{
		if (pars->i > 0)
		{
			if (!input_words(pars->words, *(s - pars->i), pars->i, pars->type))
				return (free_words(pars->words, ""));
		}
		if (*s + 1 && *((*s) + 1) == '<')
		{
			if (!input_words(pars->words, *s, 2, pars->type))
				return (free_words(pars->words, ""));
			(*s)++;
			pars->pos++;
		}
		else
		{
			if (!input_words(pars->words, *s, 1, pars->type))
				return (free_words(pars->words, ""));
		}
		pars->i = 0;
		pars->type = 0;
		return (1);
	}
	return (2);
}

int	put_words7(t_pars *pars, char *s)
{
	if (pars->type != 1 && pars->type != 2 && *s == '\\')
	{
		(pars->i)++;
		*s = 0;
		return (1);
	}
	else if (*s == '\\' && ((pars->type == 1 && (s + 1) && *(s + 1) == '"')
			|| (pars->type == 2 && (s + 1) && *(s + 1) == '\'')))
	{
		*s = 0;
		pars->i += 2;
		s += 2;
		return (1);
	}
	else if (pars->type != 1 && pars->type != 2 && pars->i > 0
		&& ((*s > 8 && *s < 14) || *s == 32))
	{
		if (!input_words(pars->words, s - pars->i, pars->i, pars->type))
			return (free_words(pars->words, ""));
		pars->i = 0;
		pars->type = 0;
		return (1);
	}
	return (2);
}

void	put_words8(t_pars *pars, char *s)
{
	if (pars->type % 10 == 0 && !((*s > 8 && *s < 14) || *s == 32))
		(pars->i)++;
	if (pars->type == 1 && *s == '"')
	{
		(pars->i)++;
		pars->type = 10;
		*s = 0;
	}
	else if (pars->type == 2 && *s == '\'')
	{
		(pars->i)++;
		pars->type = 20;
		*s = 0;
	}
	else if (pars->type == 1 && *s != '"')
		(pars->i)++;
	else if (pars->type == 2 && *s != '\'')
		(pars->i)++;
}
