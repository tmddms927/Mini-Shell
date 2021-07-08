/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:43:48 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/07 22:08:42 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int					error_free(char *s, t_list *list)
{
	t_com			*temp;
	t_com			*next;
	int				i;

	temp = list->head;
	next = temp;
	while (temp)
	{
		i = 0;
		if (temp->c)
			free(temp->c);
		if (temp->re_head)
			free(temp->re_head);
		if (temp->argv)
		{
			while (temp->argv[i])
			{
				free(temp->argv[i]);
				i++;
			}
			free(temp->argv);
			i = 0;
		}
		if (temp->path)
		{
			while (temp->path[i])
				free(temp->path[i++]);
			free(temp->path);
		}
		next = temp->next;
		free(temp);
		temp = next;
	}
	list->head = 0;
	return (0);
}

size_t			ft_strlen(char *s)
{
	int			i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int				ft_strcat_s(char **s1, char **s2)
{
	size_t		len1;
	size_t		len2;
	size_t		i;
	char		*temp;

	i = -1;
	len1 = ft_strlen(*s1);
	len2 = ft_strlen(*s2);
	temp = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!temp)
		return (0);
	while (++i < len1)
		temp[i] = (*s1)[i];
	while (*s2 && (*s2)[i])
	{
		temp[i] = (*s2)[i];
		i++;
	}
	temp[i] = 0;
	if (*s1)
		free(*s1);
	if (*s2)
		free(*s2);
	*s1 = temp;
	return (1);
}

int				ft_strcat_c(char **s1, char s2)
{
	size_t		len1;
	size_t		i;
	char		*temp;

	i = -1;
	len1 = ft_strlen(*s1);
	temp = (char *)malloc(sizeof(char) * (len1 + 2));
	if (!temp)
		return (0);
	while (++i < len1)
		temp[i] = (*s1)[i];
	temp[i++] = s2;
	temp[i] = 0;
	if (*s1)
		free(*s1);
	*s1 = temp;
	return (1);
}


void			free_split_words(char **words)
{
	int			i;

	i = 0;
	if (words)
	{
		while (words[i])
		{
			free(words[i]);
			i++;
		}
		free(words);
	}
}

void			print_list(t_list *list)
{
	t_com		*temp;
	t_re		*re;
	int			i;

	temp = list->head;
	while (temp)
	{
		i = -1;
		printf("======================\n");
		printf("command : %s\n", temp->c);
		while (temp->argv[++i])
			printf("argument(%d) : %s\n", i + 1, temp->argv[i]);
		i = -1;
		if (temp->path)
		{
			while (temp->path[++i])
				printf("path(%d) : %s\n", i + 1, temp->path[i]);
		}
		re = temp->re_head;
		while (re)
		{
			printf("redirection : %s\n", re->file);
			re = re->next;
		}
		temp = temp->next;
	}
}