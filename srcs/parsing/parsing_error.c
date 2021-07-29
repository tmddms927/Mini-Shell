/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 18:09:46 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/28 23:38:07 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check2(t_com *com)
{
	int	check;
	t_re	*re;

	check = 0;
	if (com->re_head)
	{
		re = com->re_head;
		while (re)
		{
			if (!re->file)
				return (error_print("minishell: syntax error\n"));
			re = re->next;
		}
		check++;
	}
	if (com->c)
		check++;
	if (!check)
		return (0);
	return (1);
}

int	check_list_error(t_list *list)
{
	t_com	*com;

	com = list->head;
	while (com)
	{
		if (!check2(com))
			return (0);
		com = com->next;
	}
	return (1);
}
