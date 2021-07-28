/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwan <hwan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 21:54:13 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/27 16:50:26 by hwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "object.h"

int	update_addenv(t_list *list, char *s, char *name)
{
	t_addenv	*temp;
	int			i;

	temp = find_addenv(list, name);
	free(temp->s);
	temp->s = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!temp->s)
		return (error_print("Error : failed malloc\n"));
	i = -1;
	while (s[++i])
		temp->s[i] = s[i];
	temp->s[i] = 0;
	return (1);
}

int	input_addenv(t_list *list, char *s, char *name)
{
	t_addenv	*temp;
	int			i;

	if (!addenv_oadd(list))
		return (0);
	temp = addenv_olast(list);
	temp->name = (char *)malloc(sizeof(char) * ft_strlen(name) + 1);
	if (!temp->name)
		return (error_print("Error : failed malloc\n"));
	i = -1;
	while (name[++i])
		temp->name[i] = name[i];
	temp->name[i] = 0;
	temp->s = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!temp->s)
		return (error_print("Error : failed malloc\n"));
	i = -1;
	while (s[++i])
		temp->s[i] = s[i];
	temp->s[i] = 0;
	return (1);
}

static void	sort_env2(t_set **front, t_set **back)
{
	char	*temp1;
	char	*temp2;

	temp1 = (*front)->name;
	temp2 = (*front)->value;
	(*front)->name = (*back)->name;
	(*front)->value = (*back)->value;
	(*back)->name = temp1;
	(*back)->value = temp2;
}

static void	sort_env(t_list *list, int check)
{
	t_set	*front;
	t_set	*back;

	while (check)
	{
		check = 0;
		front = list->set;
		back = front->next;
		while (front && back)
		{
			if (ft_strcmp(front->name, back->name) > 0)
			{
				sort_env2(&front, &back);
				check = 1;
			}
			front = back;
			back = back->next;
		}
	}
}

int	export(t_list *list, t_com *com)
{
	t_set	*temp;

	if (com->argv[1])
		return (export_argv(list, com));
	sort_env(list, 1);
	temp = list->set;
	while (temp)
	{
		if (!ft_strcmp(temp->name, "?\0"))
		{
			temp = temp->next;
			continue ;
		}
		printf("declare -x ");
		printf("%s=", temp->name);
		if (temp->value[0])
			printf("\"%s\"\n", temp->value);
		else
			printf("\n");
		temp = temp->next;
	}
	return (1);
}
