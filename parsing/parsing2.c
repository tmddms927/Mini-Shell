/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 05:40:28 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/07 07:22:38 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			set_list(t_list *list, char **words)
{
	t_com	*com;
	
	if (!oadd(list))
		return (0);
	com = olast(list);
	printf("set : %s\n", set_command(words[0]));
	com->c = set_command(words[0]);
	printf("finish : %s\n", com->c);
}

char		*set_command(char *word)
{
	int		i;
	char	*com;

	i = 0;
	com = 0;
	while (word[i])
	{
		if (word[i] == '|')
		{
			printf("|\n");
		}
		if (word[i] == '<' || word[i] == '>')
		{
			printf("< >\n");
		}
		if (word[i] == '\'' || word[i] == '"')
		{
			printf("\'\"\n");
		}
		com = ft_strcat(com, word[i]);
		i++;
	}
	return (com);
}
