/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:25:45 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/24 18:04:39 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "object.h"

/*
** 프로그램 시작시 set 저장
*/

int	set_set(t_list *list)
{
	int		i;

	i = -1;
	while (list->envp[++i])
	{
		if (check_variable(list->envp[i]))
		{
			if (!set_oadd(list))
				return (0);
			if (!save_set(list, list->envp[i]))
				return (0);
		}
	}
	return (1);
}

/*
** set에 저장될 변수 인지 확인 (맞으면 1, 틀리면 0)
*/

int	check_variable(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

/*
** set에 variable 저장하기
*/

int	save_set(t_list *list, char *s)
{
	int 	i;
	int		j;
	t_set	*temp;

	i = 0;
	temp = set_olast(list);
	while (s[i] != '=')
		i++;
	j = -1;
	temp->name = (char *)malloc(sizeof(char) * (i + 1));
	if (!temp->name)
		return (error_print("Error : failed malloc\n"));
	while (++j < i)
		temp->name[j] = s[j];
	temp->name[j] = 0;
	while (s[i])
		i++;
	temp->value = (char *)malloc(sizeof(char) * (i - j + 1));
	if (!temp->value)
		return (error_print("Error : failed malloc\n"));
	i = 0;
	while (s[++j])
		temp->value[i++] = s[j];
	temp->value[i] = 0;
	return (1);
}

/*
** set print
*/

void	print_set(t_list *list)
{
	t_set *temp;

	temp = list->set;
	while (temp)
	{
		printf("===> name : %s\n===> value : %s\n",
			temp->name, temp->value);
		temp = temp->next;
	}
}
