/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:11:44 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/21 17:31:43 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	count_word(char *s)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (i > 0 && (*s == '=' || *s == ':'))
		{
			i = 0;
			count++;
		}
		else if (!(*s == '=' || *s == ':'))
			i++;
		s++;
	}
	if (i > 0)
		count++;
	return (count);
}

static char	**free_all(char **words, int j)
{
	while (j-- > 0)
		free(words[j]);
	free(words);
	return (0);
}

static int	put_char(char **s, char *c, int i)
{
	int			j;

	*s = (char *)malloc(sizeof(char) * (i + 1));
	if (!*s)
		return (0);
	j = 0;
	while (j < i)
	{
		(*s)[j] = c[j];
		j++;
	}
	(*s)[j] = 0;
	return (1);
}

static char	**put_words(char **words, char *s)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (i > 0 && (*s == '=' || *s == ':'))
		{
			if (!put_char(&words[j++], (char *)s - i, i))
				return (free_all(words, j));
			i = 0;
		}
		else if (!(*s == '=' || *s == ':'))
			i++;
		s++;
	}
	if (i > 0)
	{
		if (!put_char(&words[j++], (char *)s - i, i))
			return (free_all(words, j));
	}
	return (words);
}

/*
** path 저장하기
*/

char	**ft_split_envp(char *s)
{
	int		words_c;
	char	**words;

	if (!s)
		return (0);
	words_c = count_word(s);
	words = (char **)malloc(sizeof(char *) * (words_c + 1));
	if (!words)
		return (0);
	if (!put_words(words, s))
		return (0);
	words[words_c] = 0;
	return (words);
}
