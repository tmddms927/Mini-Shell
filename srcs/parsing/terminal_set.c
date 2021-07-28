/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:45:54 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/27 14:50:38 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// org_term에 초기 터미널 세팅 저장
void save_input_mode(t_list *list)
{
	tcgetattr(STDIN_FILENO, &(list->org_term)); // STDIN으로부터 터미널 속성을 받아온다
}

// new_term에 원하는 터미널 속성 설정
void set_input_mode(t_list *list)
{
	tcgetattr(STDIN_FILENO, &(list->new_term));			 // STDIN으로부터 터미널 속성을 받아온다
	list->new_term.c_lflag &= ~(ICANON | ECHO);		 // ICANON, ECHO 속성을 off
	list->new_term.c_cc[VMIN] = 1;					 // 1 바이트씩 처리
	list->new_term.c_cc[VTIME] = 0;					 // 시간은 설정하지 않음
	tcsetattr(STDIN_FILENO, TCSANOW, &(list->new_term)); // 변경된 속성의 터미널을 STDIN에 바로 적용
}

// 기존의 터미널 세팅으로 다시 변경
void reset_input_mode(t_list *list)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &(list->org_term));  // STDIN에 기존의 터미널 속성을 바로 적용
}