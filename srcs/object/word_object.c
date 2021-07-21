/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:50:27 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/21 16:29:54 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

/*
** word 생성 후 마지막 원소 뒤에 붙여주기
*/

int	words_oadd(t_words *words)
{
	t_word		*temp;
	t_word		*word;

	word = (t_word *)malloc(sizeof(t_word));
	if (!word)
		return (free_words(words, "Error : failed malloc\n"));
	temp = words_olast(words);
	if (!temp)
		words->head = word;
	else
		temp->next = word;
	word->next = 0;
	return (1);
}

/*
** word의 마지막 원소 찾기
*/

t_word	*words_olast(t_words *words)
{
	t_word		*temp;

	temp = words->head;
	if (!temp)
		return (temp);
	while (temp->next)
		temp = temp->next;
	return (temp);
}
