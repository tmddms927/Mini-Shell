/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:57:34 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/30 17:56:40 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "object.h"
#include "exec.h"

static int	g_t;

static t_set	*set2(char *s, t_set **temp, int i, int j)
{
	if (!s[i])
	{
		(*temp)->value = 0;
		return (*temp);
	}
	while (s[i])
		i++;
	(*temp)->value = (char *)malloc(sizeof(char) * (i - j + 1));
	if (!(*temp)->value)
		return (export_error("Error : failed malloc\n"));
	i = 0;
	if (!s[j])
	{
		(*temp)->value[i] = 0;
		return (*temp);
	}
	while (s[++j])
		(*temp)->value[i++] = s[j];
	(*temp)->value[i] = 0;
	return (*temp);
}

static t_set	*set(char *s)
{
	int		i;
	t_set	*temp;
	int		j;

	i = 0;
	temp = (t_set *)malloc(sizeof(t_set));
	if (!temp)
		return (export_error("Error : failed malloc\n"));
	while (s[i] && s[i] != '=')
		i++;
	temp->name = (char *)malloc(sizeof(char) * (i + 1));
	if (!temp->name)
		return (export_error("Error : failed malloc\n"));
	j = -1;
	while (++j < i)
		temp->name[j] = s[j];
	temp->name[j] = 0;
	if (!set2(s, &temp, i, j))
		return (0);
	temp->next = 0;
	return (temp);
}

static int	sub3(t_list *list, t_set *temp, t_set *temp2, t_com *com)
{
	temp2 = set_olast(list);
	if (!temp2)
		list->set = temp;
	else
		temp2->next = temp;
	if (set_olast(list)->value)
	{
		if (!input_env(list, com->argv[g_t], temp->name))
			return (0);
	}
	return (1);
}

static int	sub2(t_list *list, t_set *temp, t_set *temp2, t_com *com)
{
	if (temp2)
	{
		if (temp->value && temp2->value)
		{
			if (!update_env(list, com->argv[g_t], temp->name))
				return (0);
		}
		else if (temp->value)
		{
			if (!input_env(list, com->argv[g_t], temp->name))
				return (0);
		}
		free(temp2->value);
		temp2->value = temp->value;
		free(temp->name);
		free(temp);
	}
	else
		return (sub3(list, temp, temp2, com));
	return (1);
}

int	export_argv(t_list *list, t_com *com)
{
	t_set	*temp;
	t_set	*temp2;

	g_t = 0;
	while (com->argv[++g_t])
	{
		if (!set_s_check(com->argv[g_t]))
			return (1);
		temp = set(com->argv[g_t]);
		temp2 = find_set(list, temp->name);
		if (!sub2(list, temp, temp2, com))
			return (1);
	}
	return (0);
}
