/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:21:10 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/26 21:30:50 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <termcap.h>

void	ctrl_backslash(int signo)
{
	(void)signo;
	//write(0, "\b \b\b \b", 6);
}

int		init_signal(void)
{
	void (*old_fun)(int);
	
	old_fun = signal(SIGINT, ctrl_c);
	old_fun = signal(SIGQUIT, ctrl_backslash);
	return (1);
}
