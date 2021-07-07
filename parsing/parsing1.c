/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:12:14 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/07 07:17:23 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			main(int argc, char **argv)
{
	// char	*s;
	// char	prompt[100];
	t_list	*list;

	list = init_list();
	if (!parsing_start(argv[1], list))
		printf("parsing error!\n");

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

int			parsing_start(char *s, t_list *list)
{
	char	**words;
	int		i;

	i = 0;
	words = ft_split(s);
	if (!set_list(list, words))
		return (0);
}
