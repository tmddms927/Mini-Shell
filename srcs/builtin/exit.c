/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 23:43:02 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/29 14:03:04 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_exit(t_com *com)
{
	int i;
	int num;

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
	num = 0;
	i = -1;
	while (com->argv[1][++i])
		num = num * 10 + com->argv[1][i] - '0';
	exit(num);
}
