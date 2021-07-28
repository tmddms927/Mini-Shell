#include "exec.h"

int	echo(char **argv, int check)
{
	int		i;
	t_bool	no_nl;

	i = 1;
	no_nl = FALSE;
	while (argv[i])
	{
		if (check == 0 && *(argv[i]) == '-')
		{
			no_nl = check_flag(argv[i], 'n');
			if (no_nl)
			{
				i++;
				continue ;
			}
		}
		check = 1;
		putstr(argv[i], 1);
		if (argv[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (!no_nl)
		putstr("\n", 1);
	return (0);
}

t_bool	check_flag(char *argv, char c)
{
	int		i;
	t_bool	ret;

	i = 1;
	ret = FALSE;
	while (argv[i])
	{
		if (argv[i] == c)
			ret = TRUE;
		if (argv[i] != c)
			return (FALSE);
		i++;
	}
	return (ret);
}

int	putstr(char *str, int fd)
{
	int	len;

	len = ft_strlen(str);
	write(fd, str, len);
	return (len);
}
