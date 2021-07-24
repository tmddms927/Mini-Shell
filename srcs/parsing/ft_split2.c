/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:47:06 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/24 21:43:44 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "split.h"

int	put_words4(t_words *words, t_pars *pars)
{
	if (pars->type != 1 && pars->type != 2 && *(pars->s) == '|')
	{
		if (pars->i > 0)
		{
			if (!input_words(words, pars->s - pars->i, pars->i, pars->type))
				return (free_words(words, ""));
		}
		if (!input_words(words, pars->s, 1, pars->type))
			return (free_words(words, ""));
		pars->i = 0;
		pars->type = 0;
		return (1);
	}
	return (2);
}

int	put_words5(t_words *words, t_pars *pars)
{
	if (pars->type != 1 && pars->type != 2 && *(pars->s) == '>')
	{
		if (pars->i > 0)
		{
			if (!input_words(words, pars->s - pars->i, pars->i, pars->type))
				return (free_words(words, ""));
		}
		if (pars->s + 1 && *(pars->s + 1) == '>')
		{
			if (!input_words(words, pars->s, 2, pars->type))
				return (free_words(words, ""));
			pars->s++;
		}
		else
		{
			if (!input_words(words, pars->s, 1, pars->type))
				return (free_words(words, ""));
		}
		pars->i = 0;
		pars->type = 0;
		return (1);
	}
	return (2);
}

int	put_words6(t_words *words, t_pars *pars)
{
	if (pars->type != 1 && pars->type != 2 && *(pars->s) == '<')
	{
		if (pars->i > 0)
		{
			if (!input_words(words, pars->s - pars->i, pars->i, pars->type))
				return (free_words(words, ""));
		}
		if (pars->s + 1 && *(pars->s + 1) == '<')
		{
			if (!input_words(words, pars->s, 2, pars->type))
				return (free_words(words, ""));
			pars->s++;
		}
		else
		{
			if (!input_words(words, pars->s, 1, pars->type))
				return (free_words(words, ""));
		}
		pars->i = 0;
		pars->type = 0;
		return (1);
	}
	return (2);
}

int	put_words7(t_words *words, t_pars *pars)
{
	if (pars->type != 1 && pars->type != 2 && *(pars->s) == '\\')
	{
		pars->i++;
		*(pars->s) = 0;
		return (1);
	}
	else if (*(pars->s) == '\\' && ((pars->type == 1 && pars->s + 1 && *(pars->s + 1) == '"')
			|| (pars->type == 2 && (pars->s + 1) && *(pars->s + 1) == '\'')))
	{
		*(pars->s) = 0;
		pars->i += 2;
		pars->s += 2;
		return (1);
	}
	else if (pars->type != 1 && pars->type != 2 && pars->i > 0
		&& ((*(pars->s) > 8 && *(pars->s) < 14) || *(pars->s) == 32))
	{
		if (!input_words(words, pars->s - pars->i, pars->i, pars->type))
			return (free_words(words, ""));
		pars->i = 0;
		pars->type = 0;
		return (1);
	}
	return (2);
}

void	put_words8(t_pars *pars)
{
	if (pars->type % 10 == 0 && !((*(pars->s) > 8 && *(pars->s) < 14) || *(pars->s) == 32))
		pars->i++;
	if (pars->type == 1 && *(pars->s) == '"')
	{
		pars->i++;
		pars->type = 10;
		*(pars->s) = 0;
	}
	else if (pars->type == 2 && *(pars->s) == '\'')
	{
		pars->i++;
		pars->type = 20;
		*(pars->s) = 0;
	}
	else if (pars->type == 1 && *(pars->s) != '"')
		pars->i++;
	else if (pars->type == 2 && *(pars->s) != '\'')
		pars->i++;
}
