/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 03:04:25 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/09 01:28:49 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "split.h"

// 0 = X, 1 = ", 2 = '
static int		put_words(t_words *words, char *s)
{
	int			type;
	int			i;

	type = 0;
	i = 0;
	while (*s)
	{
		if (type % 10 == 0 && *s == '"')
		{
			i++;
			type = 1;
			*s = 0;
		}
		else if (type % 10 == 0 && *s == '\'')
		{
			i++;
			type = 2;
			*s = 0;
		}
		else if (type != 1 && type != 2 && *s == '|')
		{
			if (i > 0)
			{
				if (!input_words(words, (char *)s - i, i, type))
					return (free_words(words, ""));
			}
			if (!input_words(words, (char *)s, 1, type))
				return (free_words(words, ""));
			i = 0;
			type = 0;
		}
		else if (type != 1 && type != 2 && *s == '>')
		{
			if (i > 0)
			{
				if (!input_words(words, (char *)s - i, i, type))
					return (free_words(words, ""));
			}
			if ((s + 1) && *(s + 1) == '>')
			{
				if (!input_words(words, (char *)s, 2, type))
					return (free_words(words, ""));		
				s++;
			}
			else
			{
				if (!input_words(words, (char *)s, 1, type))
					return (free_words(words, ""));
			}
			i = 0;
			type = 0;
		}
		else if (type != 1 && type != 2 && *s == '<')
		{
			if (i > 0)
			{
				if (!input_words(words, (char *)s - i, i, type))
					return (free_words(words, ""));
			}
			if ((s + 1) && *(s + 1) == '<')
			{
				if (!input_words(words, (char *)s, 2, type))
					return (free_words(words, ""));
				s++;
			}
			else
			{
				if (!input_words(words, (char *)s, 1, type))
					return (free_words(words, ""));
			}
			i = 0;
			type = 0;
		}
		else if (type != 1 && type != 2 && *s == '\\')
		{
			i++;
			*s = 0;
		}
		else if (*s == '\\' && ((type == 1 && (s + 1) && *(s + 1) == '"') || 
				(type == 2 && (s + 1) && *(s + 1) == '\'')))
		{
			*s = 0;
			i += 2;
			s += 2;
		}
		else if (type != 1 && type != 2 && i > 0 && ((*s > 8 && *s < 14) || *s == 32))
		{
			if (!input_words(words, (char *)s - i, i, type))
				return (free_words(words, ""));
			i = 0;
			type = 0;
		}
		else if (type == 0 && !((*s > 8 && *s < 14) || *s == 32))
			i++;
		else if (type == 1 && *s == '"')
		{
			i++;
			type = 10;
			*s = 0;
		}
		else if (type == 2 && *s == '\'')
		{
			i++;
			type = 20;
			*s = 0;
		}
		else if (type == 1 && *s != '"')
			i++;
		else if (type == 2 && *s != '\'')
			i++;
		s++;
	}
	if (i > 0 && (type == 1 || type == 2))
		return (free_words(words, "Error : unclosed quotes\n"));
	if (i > 0)
	{
		if (!input_words(words, (char *)s - i, i, type))
			return (free_words(words, ""));
	}
	return (1);
}

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

int			ft_split(t_words *words, char *s)
{	
	if (!s)
		return (free_words(words, ""));
	if (!put_words(words, s))
		return (0);
	//print_word(words);
	return (1);
}
