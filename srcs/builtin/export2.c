/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:49:36 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/29 16:42:03 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "object.h"
#include "exec.h"

static int	s_check2(int i, int *check, char *s)
{
	if (s[i] == '=' && *check == 1)
		*check = 2;
	else if (!(s[i] >= 'a' && s[i] <= 'z')
		&& !(s[i] >= 'A' && s[i] <= 'Z') && *check == 0)
	{
		printf("minishell: export: '%s': not a valid identifier\n", s);
		return (0);
	}
	else if (!(s[i] >= 'a' && s[i] <= 'z')
		&& !(s[i] >= 'A' && s[i] <= 'Z')
		&& !(s[i] >= '0' && s[i] <= '9') && *check == 1)
	{
		printf("minishell: export: '%s': not a valid identifier\n", s);
		return (0);
	}
	else if (*check % 2 == 0)
		(*check)++;
	return (1);
}

int	set_s_check(char *s)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (s[i])
	{
		if (!s_check2(i, &check, s))
			return (0);
		i++;
	}
	return (1);
}
