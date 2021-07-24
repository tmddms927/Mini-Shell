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
		ft_memmove(tmp, cont);
		ft_memmove(tmp + ft_strlen(cont), s);
		free(cont);
		free(s);
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

int	ft_memmove(char *dest, char *src)
{
	int	i;

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


void	read_endl(int fd, char *code)
{
	char	*s;
	char	prompt[3] = "> \0";

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
	}
}