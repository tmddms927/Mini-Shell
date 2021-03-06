/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:54:13 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/28 17:35:00 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	char	*temp;
	int		i;

	i = -1;
	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (single_str(s2));
	else if (!s2)
		return (single_str2(s1));
	temp = (char *)malloc(sizeof(char)
			* (gnl_ft_strlen(s1) + gnl_ft_strlen(s2) + 1));
	if (!temp)
		return (0);
	while (s1[++i])
		temp[i] = s1[i];
	while (*s2)
		temp[i++] = *s2++;
	temp[i] = 0;
	free(s1);
	return (temp);
}

char	*single_str(char *s)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)malloc(sizeof(char) * (gnl_ft_strlen(s) + 1));
	if (!temp)
		return (0);
	while (*s)
		temp[i++] = *s++;
	temp[i] = 0;
	return (temp);
}

char	*single_str2(char *s)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)malloc(sizeof(char) * (gnl_ft_strlen(s) + 1));
	if (!temp)
		return (0);
	while (*s)
		temp[i++] = *s++;
	temp[i] = 0;
	free(s);
	return (temp);
}
