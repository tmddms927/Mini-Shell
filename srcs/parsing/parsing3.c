/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 03:23:21 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/08 20:14:49 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				check_redi(t_list *list, char *s)
{
	t_com		*temp;
	t_re		*re;

	temp = olast(list);
	re = re_olast(list);
	if (s[0] == '<' && s[1] == '<')
	{
		temp->type = RE;
		re->type = H_DOC;
		return (2);
	}
	else if (s[0] == '>' && s[1] == '>')
	{
		temp->type = RE;
		re->type = APPEND;
		return (2);
	}
	else if (s[0] == '<')
	{
		temp->type = RE;
		re->type = RE_IN;
		return (1);
	}
	else if (s[0] == '>')
	{
		temp->type = RE;
		re->type = RE_OUT;
		return (1);
	}
	return (0);
}