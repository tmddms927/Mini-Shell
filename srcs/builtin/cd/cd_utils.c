#include "exec.h"
#include "object.h"
#include <limits.h>
#include <errno.h>

t_bool	get_home(char *path, t_list *list)
{
	t_set	*p;

	p = find_set(list, "HOME");
	if (p && p->value)
	{
		ft_memmove(path, p->value, ft_strlen(p->value));
		return (TRUE);
	}
	return (FALSE);
}

int	set_curpath(char *curpath, char *dir)
{
	char	path[PATH_MAX];
	int		len;

	if (!getcwd(path, PATH_MAX))
		return (return_error("minishell", "cd", errno, 1));
	if (*dir == '/')
		ft_memmove(curpath, dir, ft_strlen(dir));
	else
	{
		len = ft_strlen(path) + ft_strlen(dir) + 1;
		ft_memmove(curpath, ft_strjoin(ft_strjoin(path, "/"), dir), len);
	}
	return (0);
}

t_bool	not_need_sl(char *curpath)
{
	int	i;

	i = 0;
	while (curpath[i])
	{
		if (!ft_strncmp(&curpath[i], "//", 2)
			|| !ft_strncmp(&curpath[i], "/\0", 2))
		{
			ft_memmove(&curpath[i], &curpath[i + 1], 1);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

t_bool	dot_handler(char *curpath)
{
	int	i;

	i = 0;
	while (curpath[i])
	{
		if (!ft_strncmp(&curpath[i], "/./", 3)
			|| !ft_strncmp(&curpath[i], "/.\0", 3))
		{
			ft_memmove(&curpath[i + 1], &curpath[i + 3],
				ft_strlen(&curpath[i + 3]));
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

t_bool	dot_dot_handler(char *curpath)
{
	int	i;
	int	pre;

	i = 0;
	pre = 0;
	while (curpath[i])
	{
		if (curpath[i] == '/')
			pre = i;
		if (!ft_strncmp(&curpath[i], "/../", 4)
			|| !ft_strncmp(&curpath[i], "/..\0", 4))
		{
			ft_memmove(&curpath[pre + 1], &curpath[i + 4],
				ft_strlen(&curpath[i + 4]));
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
