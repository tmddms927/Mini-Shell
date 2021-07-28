/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 21:20:11 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/28 21:20:12 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <fcntl.h>

void	find_tty(void)
{
	int		fd2;

	if (!isatty(STDIN_FILENO))
	{
		fd2 = open(ttyname(2), O_RDWR | O_TRUNC);
		dup2(fd2, STDIN_FILENO);
	}
}
