/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:45:54 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/28 17:57:06 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** 초기 터미널 세팅 저장
*/

void	save_input_mode(t_list *list)
{
	tcgetattr(STDIN_FILENO, &(list->org_term));
}

/*
** 원하는 터미널 속성 설정
*/

void	set_input_mode(t_list *list)
{
	tcgetattr(STDIN_FILENO, &(list->new_term));
	list->new_term.c_lflag &= ~(ICANON | ECHO);
	list->new_term.c_cc[VMIN] = 1;
	list->new_term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &(list->new_term));
}

/*
** 기존의 터미널 세팅으로 다시 변경
*/

void	reset_input_mode(t_list *list)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &(list->org_term));
}
