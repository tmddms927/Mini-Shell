/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:21:10 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/29 13:32:38 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ctrl_backslash_non(int signo)
{
	(void)signo;
}

void	ctrl_backslash_can(int signo)
{
	if (signo == 3)
		write(1, "Quit: 3\n", 9);
}

void	ctrl_c_can(int signo)
{
	if (signo == 2)
		write(1, "\n", 2);
}

int	init_signal_can(void)
{
	signal(SIGINT, ctrl_c_can);
	signal(SIGQUIT, ctrl_backslash_can);
	return (1);
}

int	init_signal_non(void)
{
	signal(SIGINT, ctrl_c_non);
	signal(SIGQUIT, ctrl_backslash_non);
	return (1);
}
