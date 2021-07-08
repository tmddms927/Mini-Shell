/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 05:40:28 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/07 22:11:25 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			set_list(t_list *list, char **words)
{
	if (!oadd(list))
		return (0);
	if (!set_command(list, words[0]))
		return (0);
	return (1);
}

int			set_command(t_list *list,char *word)
{
	int		i;
	char	*com;

	i = 0;
	com = 0;
	while (word[i])
	{
		if (word[i] == '|')
		{
			if (!input_list(list, com))
				return (0);
			com = 0;
			if (!oadd(list))
				return (0);
			i++;
			continue ;
		}
		if (word[i] == '<' || word[i] == '>')
			;
		if (word[i] == '\'' || word[i] == '"')
			;
		if (!ft_strcat_c(&com, word[i]))
			return (0);
		i++;
	}
	if (!input_list(list, com))
		return (0);
	return (1);
}

int			input_list(t_list *list, char *s)
{
	t_com	*temp;

	temp = olast(list);
	if (!temp->c)
	{
		if (!ft_strcat_s(&temp->c, &s))
			return (0);
	}
	else if (!put_argument(list, s))
		return (0);
	return (1);
}


int				put_argument(t_list *list, char *s)
{
	t_com		*temp;
	char		**argv;
	int			i;
	int			j;

	temp = olast(list);
	i = 0;
	while (temp->argv[i])
		i++;
	argv = (char **)malloc(sizeof(char *) * (i + 2));
	if (!argv)
		return (error_free("Error : failed malloc\n", list));
	j = -1;
	while (++j < i)
		argv[j] = temp->argv[j];
	argv[j] = 0;
	if (!ft_strcat_s(&argv[j++], &s))
		return (0);
	argv[j++] = 0;
	free(temp->argv);
	temp->argv = argv;
}
