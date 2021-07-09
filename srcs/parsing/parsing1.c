/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:12:14 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/09 01:36:42 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			main(int argc, char **argv)
{
	// char	*s;
	// char	prompt[100];
	t_list	*list;

	(void)argc;
	list = init_list();
	//save history
	if (!parsing_start(argv[1], list))
		return (0);
	// while (1)
	// {
	// 	s = readline(prompt);
	// 	printf("%s\n", prompt);
	// 	head = parsing_start(s);
	// 	if (!head.head)
	// 		continue ;
	// }
	print_list(list);
	error_list_free("", list);
	free(list);
	// return (0);
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
	/////////////set path & set $
	if (!set_list(list, words))
		return (0);
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