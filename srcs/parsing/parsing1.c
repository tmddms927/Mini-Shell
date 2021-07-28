/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:12:14 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/28 16:42:07 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "header.h"
#include "exec.h"
#include "object.h"
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv, char **envp)
{
	char	*s;
	t_list	*list;

	init_signal();
	list = init_list(argc, argv, envp);	
	if (!list)
		return (free_list(list, "list malloc failed\n"));
	write(1, "prompt > ", 9);
	while (1)
	{
		set_input_mode(list);
		if (!get_next_line(0, &s, list))
			 continue ;
		write(0, "\n", 1);
		reset_input_mode(list);
		his_oadd(list, s);
		if (!parsing_start(s, list))
		{
			free(s);
			continue ;
		}
		snatch_error(exec(list), list);
		error_list_free("", list);
		write(1, "\nprompt > ", 10);
	}
	return (free_list(list, ""));
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
	if (!ft_split(words, s, list))
		return (0);
	if (!set_list(list, words))
	{
		free_list(list, "");
		return (0);
	}
	set_path_in_com(list);
	free_words(words, "");
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
