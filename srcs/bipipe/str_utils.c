#include "bipipe.h"

char		*ft_strjoin(char *cont, char *s)
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
		src_len	= ft_strlen(s);
		if (!(tmp = (char *)malloc(dest_len + src_len + 1)))
			return (0);
		ft_memset(tmp, dest_len + src_len + 1);
		ft_memmove(tmp, cont);
		ft_memmove(tmp + ft_strlen(cont), s);
		free(cont);
		free(s);
	}
	return (tmp);
}

void	ft_memset(char *p, unsigned int size)
{
	int i;

	i = 0;
	if (!p)
		return ;
	while ((unsigned int)i < size)
	{
		p[i] = 0;
		i++;
	}
}

int		ft_memmove(char *dest, char *src)
{
	int i;

	i = 0;
	if (!dest || !src)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}

// int		ft_strlen(char *s)
// {
// 	int i;
// 	i = 0;

// 	if (!s || !*s)
// 		return (0);
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// int		ft_strcmp(char *s1, char *s2)
// {
// 	int i;

// 	i = 0;
// 	while (s1[i] && s2[i])
// 	{
// 		if (s1[i] != s2[i])
// 			return(s1[i] - s2[i]);
// 		i++;
// 	}
// 	return (s1[i] - s2[i]);
// }