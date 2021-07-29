/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:12:14 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/28 23:38:42 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "object.h"
#include <fcntl.h>
#include "get_next_line.h"

static int	parsing_start2(t_list *list, t_words *words)
{
	if (!set_list(list, words))
	{
		free_list(list, "");
		return (0);
	}
	if (!check_list_error(list))
	{
		free_words(words, "");
		return (error_list_free("", list));
	}
	set_path_in_com(list);
	free_words(words, "");
	return (1);
}

/*
** parsing main function
*/

int	parsing_start(char *s, t_list *list)
{
	t_words	*words;

	words = (t_words *)malloc(sizeof(t_words));
	if (!words)
		return (error_print("Error : failed malloc\n"));
	words->head = 0;
	if (!*s)
		return (0);
	his_oadd(list, s);
	if (!ft_split(words, s, list))
		return (0);
	if (!parsing_start2(list, words))
		return (0);
	return (1);
}

int	set_list(t_list *list, t_words *words)
{
	t_word	*word;

	if (!com_oadd(list))
		return (0);
	word = words->head;
	while (word)
	{
		if (!set_command(list, word->s))
		{
			free_list(list, "");
			return (0);
		}
		word = word->next;
	}
	return (1);
}
