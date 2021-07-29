/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:43:48 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/29 16:19:21 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	error_list_free(char *s, t_list *list)
{
	t_com			*temp;
	t_com			*next;
	int				i;

	printf("%s", s);
	temp = list->head;
	while (temp)
	{
		i = 0;
		if (temp->c)
			free(temp->c);
		if (temp->argv)
		{
			while (temp->argv[i])
				free(temp->argv[i++]);
			free(temp->argv);
		}
		error_list_free2(temp);
		next = temp->next;
		free(temp);
		temp = next;
	}
	free_path(list);
	list->head = 0;
	return (0);
}

void	error_list_free2(t_com *temp)
{
	int				i;
	t_re			*re_temp;
	t_re			*re_next;

	i = 0;
	if (temp->path)
	{
		while (temp->path[i])
			free(temp->path[i++]);
		free(temp->path);
	}
	if (temp->re_head)
	{
		re_temp = temp->re_head;
		while (re_temp)
		{
			re_next = re_temp->next;
			free(re_temp->file);
			free(re_temp);
			re_temp = re_next;
		}
	}
}

int	free_words(t_words *words, char *s)
{
	t_word			*temp;
	t_word			*next;

	printf("%s", s);
	temp = words->head;
	while (temp)
	{
		next = temp->next;
		free(temp->s);
		free(temp);
		temp = next;
	}
	free(words);
	return (0);
}

int	error_print(char *s)
{
	printf("%s", s);
	return (0);
}

void	print_list(t_list *list)
{
	t_com			*temp;
	t_re			*re;
	int				i;

	temp = list->head;
	while (temp)
	{
		i = -1;
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
			printf("redirection : %d, filename : %s\n", re->type, re->file);
			re = re->next;
		}
		temp = temp->next;
	}
}
