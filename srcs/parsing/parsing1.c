/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:12:14 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/13 23:45:03 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			main(int argc, char **argv, char **envp)
{
	char	*s;
	char	prompt[100] = "prompt > ";
	t_list	*list;

	list = init_list(argc, argv, envp);
	if (!list)
		return (free_list(list, "list malloc failed\n"));
	while (1)
	{
		s = readline(prompt);
		add_history(s);
		if (!parsing_start(s, list))
			return (free_list(list, ""));
		print_list(list);
		error_list_free("", list);
	}
	return (free_list(list, ""));
}

/*
** parsing main function
*/

int			parsing_start(char *s, t_list *list)
{
	t_words	*words;

	words = (t_words *)malloc(sizeof(t_words));
	if (!words)
		return (error_print("Error : failed malloc\n"));
	words->head = 0;
	if (!ft_split(words, s))
		return (0);
	/////////////set $
	if (!set_list(list, words))
		return (0);
	set_path_in_com(list);
	free_words(words, "");
	return (1);
}

int			set_list(t_list *list, t_words *words)
{
	t_word	*word;
	
	if (!oadd(list))
		return (0);
	word = words->head;
	while (word)
	{
		if (!set_command(list, word->s))
			return (0);
		word = word->next;
	}
	return (1);
}
