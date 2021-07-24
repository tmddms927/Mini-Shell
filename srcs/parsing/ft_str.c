/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 03:37:18 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/24 20:08:16 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** 문자열 비교 함수
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
** 문자열 길이 반환 함수
*/

size_t	ft_strlen(char *s)
{
	int			i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

/*
** 문자열 복사
*/

int	ft_strcat_s(char **s1, char **s2)
{
	size_t		len1;
	size_t		len2;
	size_t		i;
	char		*temp;

	i = -1;
	len1 = ft_strlen(*s1);
	len2 = ft_strlen(*s2);
	temp = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!temp)
		return (0);
	while (++i < len1)
		temp[i] = (*s1)[i];
	while (*s2 && (*s2)[i - len1])
	{
		temp[i] = (*s2)[i - len1];
		i++;
	}
	temp[i] = 0;
	if (*s1)
		free(*s1);
	*s1 = temp;
	return (1);
}
