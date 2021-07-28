/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:21:10 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/28 18:00:23 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	nothing(int signo)
{
	(void)signo;
}

int	init_signal(void)
{
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, nothing);
	return (1);
}
