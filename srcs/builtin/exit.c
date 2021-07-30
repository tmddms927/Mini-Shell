/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 23:43:02 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/30 14:58:28 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_exit2(t_com *com)
{
	int	i;
	int	num;

	num = 0;
	i = -1;
	while (com->argv[1][++i])
	{
		if (com->argv[1][i] < '0' || com->argv[1][i] > '9')
		{
			printf("minishell: exit: ");
			printf("%s: numeric argument required\n", com->argv[1]);
			return (255);
		}
		num = num * 10 + com->argv[1][i] - '0';
	}
	exit(num);
}

int	ft_exit(t_com *com)
{
	int	i;

	i = 0;
	if (!com->argv[1])
		exit(0);
	while (com->argv[i])
		i++;
	if (i > 2)
	{
		printf("exit: too many arguments\n");
		return (1);
	}
	return (ft_exit2(com));
}
