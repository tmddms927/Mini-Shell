/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   his_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:22:25 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/28 20:35:59 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

static int	input_s(t_his *temp, char *s)
{
	int		len;
	int		i;

	len = ft_strlen(s);
	temp->s = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp->s)
		return (0);
	i = -1;
	while (++i < len)
		temp->s[i] = s[i];
	temp->s[i] = 0;
	return (1);
}

static void	his_oadd2(t_list *list, t_his *temp)
{
	t_his	*before;
	t_his	*temp2;

	temp2 = list->his->head;
	if (!temp2)
	{
		list->his->head = temp;
		return ;
	}
	while (temp2)
	{
		before = temp2;
		temp2 = temp2->next;
	}
	before->next = temp;
	temp->before = before;
}

/*
** his 생성 후 마지막 원소 뒤에 붙여주기
*/

int	his_oadd(t_list *list, char *s)
{
	t_his	*temp;

	temp = (t_his *)malloc(sizeof(t_his));
	if (!temp)
		return (error_list_free("Error : failed malloc\n", list));
	temp->before = 0;
	temp->next = 0;
	if (!input_s(temp, s))
		return (error_list_free("Error : failed malloc\n", list));
	his_oadd2(list, temp);
	list->his_here = temp;
	list->his_check = 0;
	return (1);
}

/*
** hisstack creat
*/

int	his_stack_oadd(t_list *list)
{
	t_his_stack	*temp;

	temp = (t_his_stack *)malloc(sizeof(t_his_stack));
	if (!temp)
		return (error_list_free("Error : failed malloc\n", list));
	list->his = temp;
	temp->head = 0;
	list->his_here = 0;
	list->his_check = 0;
	return (1);
}

t_his	*his_olast(t_list *list)
{
	t_his	*temp;

	temp = list->his->head;
	if (!temp)
		return (temp);
	while (temp->next)
		temp = temp->next;
	return (temp);
}
