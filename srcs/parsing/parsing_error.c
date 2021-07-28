/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 18:09:46 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/28 21:01:45 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_list_error(t_list *list)
{
	t_com	*com;
	t_re	*re;

	com = list->head;
	while (com)
	{
		if (com->re_head)
		{
			re = com->re_head;
			while (re)
			{
				if (!re->file)
					return (error_print("minishell: syntax error\n"));
				re = re->next;
			}
		}
		com = com->next;
	}
	return (1);
}
