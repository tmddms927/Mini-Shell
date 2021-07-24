/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:45:35 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/24 22:02:03 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "object.h"

static char	*variable(t_list *list, char *s, int i)
{
	char	*vari;
	t_set	*temp;
	int		j;

	vari = (char *)malloc(sizeof(char) * i);
	if (!vari)
		return (0);
	j = -1;
	while (++j < i)
		vari[j] = s[j + 1];
	vari[j] = 0;
	temp = list->set;
	while (temp)
	{
		if (!ft_strcmp(temp->name, vari))
		{
			free(vari);
			return (temp->value);
		}
		temp = temp->next;
	}
	free(vari);
	vari = (char *)malloc(sizeof(char) * 2);
	if (!vari)
		return (0);
	vari[0] = ' ';
	vari[1] = 0;
	return (vari);
}

static int	change_s(char **s, int j, t_list *list)
{
	size_t	len;
	char	*temp;
	char	*vari;
	int		i;
	
	vari = variable(list, *s, j);
	if (!vari)
		return (0);
	len = ft_strlen(*s) - j + 1;
	len += ft_strlen(vari);
	temp = (char *)malloc(sizeof(char) * len);
	if (!temp)
		return (error_print("Error : failed malloc\n"));
	i = -1;
	while (vari[++i])
		temp[i] = vari[i];
	while ((*s)[++j])
		temp[i++] = (*s)[++j];
	free(*s);
	*s = temp;
	return (1);
}

int	variable_in_set(t_pars *pars, t_list *list, char **s)
{
	int		j;
	
	(void)pars;
	j = 0;
	while ((*s)[j] && (*s)[j] != ' ' && (*s)[j] != '$')
		j++;
	if (j == 0)
		return (1);
	else
	{
		if (!change_s(s, j, list))
			return (0);
	}
	return (1);
}
