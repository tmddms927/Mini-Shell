/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 23:00:22 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/28 16:47:59 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <readline/readline.h>

int	do_builtin(t_list *list, t_com *com)
{
	if (!com->c)
		return (-1);
	if (!ft_strcmp("/echo\0", com->c))
		return (echo(com->argv));
	else if (!ft_strcmp("/cd\0", com->c))
		return (cd(list, com->argv));
	else if (!ft_strcmp("/pwd\0", com->c))
		return (pwd());
	else if (!ft_strcmp("/export\0", com->c))
		return (export(list, com));
	else if (!ft_strcmp("/unset\0", com->c))
		return (unset(list, com));
	else if (!ft_strcmp("/env\0", com->c))
		return (env(list));
	else if (!ft_strcmp("/exit\0", com->c))
		return (ft_exit());
	return (-1);
}
