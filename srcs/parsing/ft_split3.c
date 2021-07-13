/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 04:39:43 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/13 05:02:35 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		count_word(char *s)
{
	int         i;
	int         count;

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

static char	    **free_all(char **words, int j)
{
	while (--j > 0)
		free(words[j]);
	free(words);
	return (0);
}

static void 	put_char(char *s, char *c, int i)
{
	int	        j;

	j = 0;
	while (j < i)
	{
		s[j] = c[j];
		j++;
	}
	s[j] = 0;
}

static char	    **put_words(char **words, char *s)
{
	int         i;
	int	        j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (i > 0 && (*s == '=' || *s == ':'))
		{
			if (!(words[j] = (char *)malloc(sizeof(char) * (i + 1))))
				return (free_all(words, j));
			put_char(words[j++], (char *)s - i, i);
			i = 0;
		}
		else if (!(*s == '=' || *s == ':'))
			i++;
		s++;
	}
	if (i > 0)
	{
		if (!(words[j] = (char *)malloc(sizeof(char) * (i + 1))))
			return (free_all(words, j));
		put_char(words[j], (char *)s - i, i);
	}
	return (words);
}

char	**ft_split_envp(char *s)
{
	int		words_c;
	char	**words;

	if (!s)
		return (0);
	words_c = count_word(s);
	if (!(words = (char **)malloc(sizeof(char *) * (words_c + 1))))
		return (0);
	if (!put_words(words, s))
		return (0);
	words[words_c] = 0;
	return (words);
}