/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:12:14 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/07 05:37:51 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			main(int argc, char **argv)
{
	// char	*s;
	// char	prompt[100];
	t_list	list;

	list = parsing_start(argv[1], list);

	// while (1)
	// {
	// 	s = readline(prompt);
	// 	printf("%s\n", prompt);
	// 	head = parsing_start(s);
	// 	if (!head.head)
	// 		continue ;
	// }
	// return (0);
}

/*
** parsing main function
*/

t_list		parsing_start(char *s, t_list list)
{
	char	**words;

	words = ft_split(s);
	int i = 0;
	set_command(words, list);
}

/*
** find command & set list
*/

void		set_command(char **words, t_list list)
{
	int		i;

	i = 0;
	while (words[i])
	{
		if (!oadd(list))
			return ;
		
	}
}