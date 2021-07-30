/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwan <hwan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 05:40:28 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/30 15:29:12 by hwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "object.h"

int	set_command(t_list *list, char *s)
{
	t_com		*temp;

	temp = com_olast(list);
	if (!ft_strcmp(s, "|"))
	{
		if (!com_oadd(list))
			return (0);
	}
	else if (!ft_strcmp(s, ">") || !ft_strcmp(s, "<") || !ft_strcmp(s, ">>")
		|| !ft_strcmp(s, "<<"))
	{
		re_oadd(list);
		check_redi(list, s);
		temp->type = RE;
	}
	else
	{
		if (!set_command2(list, s, temp))
			return (0);
	}
	return (1);
}

int	set_command2(t_list *list, char *s, t_com *temp)
{
	if (temp->type == COM)
	{
		if (!ft_strcat_s(&temp->c, &s))
			return (error_list_free("Error : failed malloc\n", list));
		if (!put_argument(list, s))
			return (0);
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

int	put_argument(t_list *list, char *s)
{
	t_com		*temp;
	char		**argv;
	int			i;
	int			j;

	temp = com_olast(list);
	i = 0;
	while (temp->argv[i])
		i++;
	argv = (char **)malloc(sizeof(char *) * (i + 2));
	if (!argv)
		return (error_list_free("Error : failed malloc\n", list));
	j = -1;
	while (++j < i)
		argv[j] = temp->argv[j];
	argv[j] = 0;
	if (!ft_strcat_s(&argv[j++], &s))
		return (error_list_free("Error : failed malloc\n", list));
	argv[j] = 0;
	free(temp->argv);
	temp->argv = argv;
	return (1);
}

int	put_re(t_list *list, char *s)
{
	t_re		*temp;
	t_com		*com;

	temp = re_olast(list);
	com = com_olast(list);
	if (!ft_strcat_s(&temp->file, &s))
		return (error_list_free("Error : failed malloc\n", list));
	if (!com->c)
		com->type = COM;
	else
		com->type = ARGV;
	return (1);
}

void	check_redi(t_list *list, char *s)
{
	t_com		*temp;
	t_re		*re;

	temp = com_olast(list);
	re = re_olast(list);
	if (s[0] == '<' && s[1] == '<')
		re->type = H_DOC;
	else if (s[0] == '>' && s[1] == '>')
		re->type = APPEND;
	else if (s[0] == '<')
		re->type = RE_IN;
	else if (s[0] == '>')
		re->type = RE_OUT;
	temp->type = RE;
}
