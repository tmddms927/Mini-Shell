/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 21:19:54 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/28 21:19:55 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	lst_len(t_com *command)
{
	t_com	*tmp;
	int		ret;

	tmp = command;
	if (!tmp)
		return (0);
	else
		ret = 1;
	while (tmp->next)
	{
		ret++;
		tmp = tmp->next;
	}
	return (ret);
}
