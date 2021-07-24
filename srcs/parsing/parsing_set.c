/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:45:35 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/24 23:58:20 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "object.h"

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

//static int	change_s2(t_pars *pars, char **s, int j)
//{
	// char *temp2;
	// char	*orin;
	
	// orin = pars->orig_s;
	// i = -1;
	// len = pars->orig_len + ft_strlen(vari);
	// temp2 = (char *)malloc(sizeof(char) * len);
	// if (!temp2)
	// 	return (error_print("Error : failed malloc\n"));
	// while (++i < pars->pos)
	// 	temp2[i] = *(orin + i);
	// j = -1;
	// char *tt;
	// tt = &temp2[i];
	// while (temp[++j])
	// 	temp2[i++] = temp[j];
	// temp2[i] = 0;
	// *s = tt;
	// pars->orig_s = temp2;
	// pars->orig_len = len;
	// free(vari);
	// return (1);
//}

static int	change_s(t_pars *pars, char **s, int j, t_list *list)
{
	size_t	len;
	char	*temp;
	char	*vari;
	int		i;
	
	vari = variable(list, *s, j);
	if (!vari)
		return (0);
	len = ft_strlen(*s) - j + 1 + ft_strlen(vari);
	temp = (char *)malloc(sizeof(char) * len);
	if (!temp)
		return (error_print("Error : failed malloc\n"));
	i = -1;
	while (vari[++i])
		temp[i] = vari[i];
	while (*((*s) + j))
	{
		temp[i++] = *((*s) + j);
		j++;
	}
	temp[i] = 0;
	
	char *temp2;
	char	*orin;
	
	orin = pars->orig_s;
	i = -1;
	len = pars->orig_len + ft_strlen(vari);
	temp2 = (char *)malloc(sizeof(char) * len);
	if (!temp2)
		return (error_print("Error : failed malloc\n"));
	while (++i < pars->pos)
		temp2[i] = *(orin + i);
	j = -1;
	char *tt;
	tt = &temp2[i];
	while (temp[++j])
		temp2[i++] = temp[j];
	temp2[i] = 0;
	*s = tt;
	pars->orig_s = temp2;
	pars->orig_len = len;
	free(vari);
	return (1);
	//if (change_s2(pars, s, j))
}

int	variable_in_set(t_pars *pars, t_list *list, char **s)
{
	int		j;

	j = 1;
	while (*(*s + j) && *((*s) + j) != ' ' && *((*s) + j) != '$'
			&& *((*s) + j) != '\'' & *((*s) + j) != '"')
		j++;
	if (j == 0)
		return (1);
	else
	{
		if (!change_s(pars, s, j, list))
			return (0);
	}
	return (1);
}
