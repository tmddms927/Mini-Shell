/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:47:06 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/23 15:39:36 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "split.h"

int	put_words4(t_words *words, char *s, int *type, int *i)
{
	if (*type != 1 && *type != 2 && *s == '|')
	{
		if (*i > 0)
		{
			if (!input_words(words, s - *i, *i, *type))
				return (free_words(words, ""));
		}
		if (!input_words(words, s, 1, *type))
			return (free_words(words, ""));
		*i = 0;
		*type = 0;
		return (1);
	}
	return (2);
}

int	put_words5(t_words *words, char **s, int *type, int *i)
{
	if (*type != 1 && *type != 2 && **s == '>')
	{
		if (*i > 0)
		{
			if (!input_words(words, *(s - *i), *i, *type))
				return (free_words(words, ""));
		}
		if (*s + 1 && *((*s) + 1) == '>')
		{
			if (!input_words(words, *s, 2, *type))
				return (free_words(words, ""));
			(*s)++;
		}
		else
		{
			if (!input_words(words, *s, 1, *type))
				return (free_words(words, ""));
		}
		*i = 0;
		*type = 0;
		return (1);
	}
	return (2);
}

int	put_words6(t_words *words, char **s, int *type, int *i)
{
	if (*type != 1 && *type != 2 && **s == '<')
	{
		if (*i > 0)
		{
			if (!input_words(words, *(s - *i), *i, *type))
				return (free_words(words, ""));
		}
		if (*s + 1 && *((*s) + 1) == '<')
		{
			if (!input_words(words, *s, 2, *type))
				return (free_words(words, ""));
			(*s)++;
		}
		else
		{
			if (!input_words(words, *s, 1, *type))
				return (free_words(words, ""));
		}
		*i = 0;
		*type = 0;
		return (1);
	}
	return (2);
}

int	put_words7(t_words *words, char *s, int *type, int *i)
{
	if (*type != 1 && *type != 2 && *s == '\\')
	{
		(*i)++;
		*s = 0;
		return (1);
	}
	else if (*s == '\\' && ((*type == 1 && (s + 1) && *(s + 1) == '"')
			|| (*type == 2 && (s + 1) && *(s + 1) == '\'')))
	{
		*s = 0;
		*i += 2;
		s += 2;
		return (1);
	}
	else if (*type != 1 && *type != 2 && *i > 0
		&& ((*s > 8 && *s < 14) || *s == 32))
	{
		if (!input_words(words, s - *i, *i, *type))
			return (free_words(words, ""));
		*i = 0;
		*type = 0;
		return (1);
	}
	return (2);
}

void	put_words8(char *s, int *type, int *i)
{
	if (*type == 0 && !((*s > 8 && *s < 14) || *s == 32))
		(*i)++;
	if (*type == 1 && *s == '"')
	{
		(*i)++;
		*type = 10;
		*s = 0;
	}
	else if (*type == 2 && *s == '\'')
	{
		(*i)++;
		*type = 20;
		*s = 0;
	}
	else if (*type == 1 && *s != '"')
		(*i)++;
	else if (*type == 2 && *s != '\'')
		(*i)++;
}
