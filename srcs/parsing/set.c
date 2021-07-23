/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:25:45 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/23 14:40:28 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	set_set(t_list *list)
{
	int		i;

	i = -1;
	while (list->envp[++i])
	{
		if (check_variable(list->envp[i]))
		{
			if (save_set(list, list->envp[i]))
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
	return (1);
}
