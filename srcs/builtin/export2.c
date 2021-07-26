/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:49:36 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/26 17:51:46 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "object.h"
#include "exec.h"

static t_set	*error(char *s)
{
	printf("%s", s);
	return (0);
}

static t_set	*set2(char *s, t_set **temp, int i)
{
	int		j;

	j = -1;
	(*temp)->name = (char *)malloc(sizeof(char) * (i + 1));
	if (!(*temp)->name)
		return (error("Error : failed malloc\n"));
	while (++j < i)
		(*temp)->name[j] = s[j];
	(*temp)->name[j] = 0;
	while (s[i])
		i++;
	(*temp)->value = (char *)malloc(sizeof(char) * (i - j + 1));
	if (!(*temp)->value)
		return (error("Error : failed malloc\n"));
	i = 0;
	while (s[++j])
		(*temp)->value[i++] = s[j];
	(*temp)->value[i] = 0;
	(*temp)->next = 0;
	return (*temp);
}

static t_set	*set(char *s)
{
	int		i;
	t_set	*temp;

	i = 0;
	temp = (t_set *)malloc(sizeof(t_set));
	if (!temp)
		return (error("Error : failed malloc\n"));
	while (s[i] && s[i] != '=')
		i++;
	if (!set2(s, &temp, i))
		return (0);
	return (temp);
}

static int	s_check(char *s)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (s[i])
	{
		if (s[i] == '=' && check == 1)
			check = 2;
		else if (!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z') && check == 0)
		{
			printf("minishell: export: '%s': not a valid identifier\n", s);
			return (0);
		}
		else if (!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z')
			&& !(s[i] >= '0' && s[i] <= '9') && check == 1)
		{
			printf("minishell: export: '%s': not a valid identifier\n", s);
			return (0);
		}
		else if (check % 2 == 0)
			check++;
		i++;
	}
	return (1);
}

int	export_argv(t_list *list, t_com *com)
{
	int t;
	t_set	*temp;
	t_set	*temp2;
	
	t = 0;
	while (com->argv[++t])
	{
		if (!s_check(com->argv[t]))
		{
			snatch_error(1, list);
			return (0);
		}
		temp = set(com->argv[t]);
		temp2 = find_set(list, temp->name);
		if (temp2)
		{
			if (!update_addenv(list, com->argv[t], temp->name))
				return (0);
			free(temp2->value);
			temp2->value = temp->value;
			free(temp->name);
			free(temp);
		}
		else
		{
			temp2 = set_olast(list);
			if (!temp2)
				list->set = temp;
			else
				temp2->next = temp;
			if (!input_addenv(list, com->argv[t], temp->name))
				return (0);
		}
	}
	return (1);
}
