/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 21:20:06 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/28 21:20:07 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*ft_strjoin(char *cont, char *s)
{
	char	*tmp;
	int		dest_len;
	int		src_len;

	tmp = 0;
	if (!cont)
		cont = s;
	else
	{
		if (!s)
			return (0);
		dest_len = ft_strlen(cont);
		src_len = ft_strlen(s);
		tmp = (char *)malloc(dest_len + src_len + 1);
		if (!tmp)
			return (0);
		ft_memset(tmp, dest_len + src_len + 1);
		ft_memmove(tmp, cont, ft_strlen(cont));
		ft_memmove(tmp + dest_len, s, ft_strlen(s));
	}
	return (tmp);
}

void	ft_memset(char *p, unsigned int size)
{
	int	i;

	i = 0;
	if (!p)
		return ;
	while ((unsigned int)i < size)
	{
		p[i] = 0;
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;
	size_t			i;

	i = 0;
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	if (dest < src && !(dest == 0 && src == 0))
	{
		while (i < num)
		{
			tmp_dest[i] = tmp_src[i];
			++i;
		}
	}
	else if (dest >= src && !(dest == 0 && src == 0))
	{
		while (i < num)
		{
			tmp_dest[num - i - 1] = tmp_src[num - i - 1];
			++i;
		}
	}
	return (dest);
}

void	read_endl(int fd, char *code)
{
	char	*s;
	char	prompt[3];

	prompt[0] = '>';
	prompt[1] = ' ';
	prompt[2] = 0;
	while (1)
	{
		s = readline(prompt);
		if (!ft_strcmp(s, code))
		{
			free(s);
			break ;
		}
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
		free(s);
	}
}

void	ft_bzero(char *s, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
		s[i++] = 0;
}
