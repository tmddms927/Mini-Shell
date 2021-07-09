/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 05:40:28 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/08 20:14:36 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			set_list(t_list *list, char **words)
{
	if (!oadd(list))
		return (0);
	if (!set_command(list, words, 0))
		return (0);
	return (1);
}

int			set_command(t_list *list, char **words, int idx)
{
	int		i;
	char	*com;
	t_com	*temp;
	
	i = 0;
	com = 0;
	while (words[idx])
	{
		while (words[idx][i])
		{
			temp = olast(list);
			if (words[idx][i] == '|')
			{
				if (com && !input_list(list, com))
					return (0);
				com = 0;
				if (!oadd(list))
					return (0);
				temp = olast(list);
				temp->type = COM;
				i++;
				continue ;
			}
			if ((temp->type != RE || com) && (words[idx][i] == '<' || words[idx][i] == '>'))
			{
				if (com && !input_list(list, com))
					return (0);
				com = 0;
				if (!re_odd(list))
					return (0);
				i += check_redi(list, words[idx] + i);
				continue ;
			}
			if (words[idx][i] == '\'' || words[idx][i] == '"')
			{
				
			}
			if (!ft_strcat_c(&com, words[idx][i]))
				return (0);
			i++;
		}
		if (com && !input_list(list, com))
			return (0);
		com = 0;
		idx++;
		i = 0;
	}
	if (com)
		free(com);
	return (1);
}

int			input_list(t_list *list, char *s)
{
	t_com	*temp;

	temp = olast(list);

	if (temp->type == COM)
	{
		if (!ft_strcat_s(&temp->c, &s))
			return (error_free("Error : failed malloc\n", list));
		temp->type = ARGV;
	}
	else if (temp->type == ARGV)
	{
		if (!put_argument(list, s))
			return (0);
	}
	else if (temp->type == RE)
	{
		if (!put_re(list, s))
			return (0);
	}
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
		return (error_free("Error : failed malloc\n", list));
	argv[j++] = 0;
	free(temp->argv);
	temp->argv = argv;
	return (1);
}

int				put_re(t_list *list, char *s)
{
	t_re		*temp;
	t_com		*com;

	temp = re_olast(list);
	com = olast(list);
	if (!ft_strcat_s(&temp->file, &s))
		return (error_free("Error : failed malloc\n", list));
	com->type = ARGV;
	return (1);
}
