/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:45:35 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/28 17:54:24 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "object.h"

static int	g_i;
static int	g_j;

static char	*variable2(char *s, char *vari)
{
	int		len;
	int		i;

	len = ft_strlen(s);
	free(vari);
	vari = (char *)malloc(sizeof(char) * (len + 1));
	if (!vari)
		return (0);
	i = -1;
	while (s[++i])
		vari[i] = s[i];
	vari[i] = 0;
	return (vari);
}

static char	*variable(t_list *list, char *s, int i)
{
	char	*vari;
	t_set	*temp;
	int		j;

	vari = (char *)malloc(sizeof(char) * i);
	if (!vari)
		return (0);
	j = -1;
	while (++j < i - 1)
		vari[j] = s[j + 1];
	vari[j] = 0;
	temp = list->set;
	while (temp)
	{
		if (!ft_strcmp(temp->name, vari))
			return (variable2(temp->value, vari));
		temp = temp->next;
	}
	return (variable2(" \0", vari));
}

static int	change_s2(t_pars *pars, char *temp, char **s, char *vari)
{
	char	*temp2;
	char	*orin;
	int		len;
	char	*tt;

	orin = pars->orig_s;
	g_i = -1;
	len = pars->orig_len + ft_strlen(vari);
	temp2 = (char *)malloc(sizeof(char) * len);
	if (!temp2)
		return (error_print("Error : failed malloc\n"));
	while (++g_i < pars->pos)
		temp2[g_i] = *(orin + g_i);
	g_j = -1;
	tt = &temp2[g_i];
	while (temp[++g_j])
		temp2[g_i++] = temp[g_j];
	temp2[g_i] = 0;
	*s = tt;
	free(pars->orig_s);
	pars->orig_s = temp2;
	pars->orig_len = len;
	return (1);
}

static int	change_s(t_pars *pars, char **s, t_list *list)
{
	size_t	len;
	char	*temp;
	char	*vari;

	vari = variable(list, *s, g_j);
	if (!vari)
		return (0);
	len = ft_strlen(*s) - g_j + 1 + ft_strlen(vari);
	temp = (char *)malloc(sizeof(char) * len);
	if (!temp)
		return (error_print("Error : failed malloc\n"));
	g_i = -1;
	while (vari[++g_i])
		temp[g_i] = vari[g_i];
	while (*((*s) + g_j))
	{
		temp[g_i++] = *((*s) + g_j);
		g_j++;
	}
	temp[g_i] = 0;
	if (!change_s2(pars, temp, s, vari))
		return (0);
	free(vari);
	free(temp);
	return (1);
}

int	variable_in_set(t_pars *pars, t_list *list, char **s)
{
	g_j = 1;
	while (*(*s + g_j) && *((*s) + g_j) != ' ' && *((*s) + g_j) != '$'
		&& *((*s) + g_j) != '\'' & *((*s) + g_j) != '"')
		g_j++;
	if (g_j == 0)
		return (1);
	else
	{
		if (!change_s(pars, s, list))
			return (0);
	}
	return (1);
}
