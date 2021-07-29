/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:00:23 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/29 16:12:49 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "get_next_line.h"
#include "object.h"

/*
** 프로그램 시작 시 list 세팅해주는 함수
*/

t_list	*init_list(int argc, char **argv, char **envp)
{
	t_list		*temp;

	(void)argc;
	(void)argv;
	temp = (t_list *)malloc(sizeof(t_list) * 1);
	if (!temp)
		return (temp);
	temp->head = 0;
	temp->envp = envp;
	temp->path = 0;
	temp->set = 0;
	temp->tty = ttyname(1);
	temp->env = 0;
	if (!his_stack_oadd(temp))
		return (0);
	save_input_mode(temp);
	if (!set_set(temp))
		return (0);
	return (temp);
}
