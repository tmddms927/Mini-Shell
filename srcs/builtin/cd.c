#include "exec.h"
#include "object.h"
#include <limits.h>

int	cd(t_list *list, char **argv)
{
	char *dir;
	char curpath[PATH_MAX];

	dir = argv[1];
	ft_bzero(&curpath, PATH_MAX);
	if (!dir)
	{
		mv_home(list);
		return (0);
	}
	set_curpath(&curpath, dir);
	while (not_need_sl(&curpath))
		;
	while (dot_handler(&curpath))
		;
	while (dot_dot_handler(&curpath))
		;
}

void	mv_home(t_list *list)
{
	char	path[PATH_MAX];

	if (get_home(&path, list))
	{
		if (path)
			chdir(path);
	}
	// return (ret);
}

t_bool	get_home(char *path, t_list *list)
{
	t_set *p;

	p = find_set(list, "HOME");
	if (p && p->value)
	{
		ft_memmove(path, p->value);
		return (TRUE);
	}
	return (FALSE);
}

char	*set_curpath(char *curpath, char *dir)
{
	if (*dir == '/')
		ft_memmove(curpath, dir);
	else
		ft_memmove(curpath, ft_strjoin(pwd(), dir));
	return (&curpath);
}

t_bool not_need_sl(char *curpath)
{
	int	i;

	i = 0;
	while (curpath[i])
	{
		if (!ft_strncmp(&curpath[i], "//", 2)
		|| ft_strncmp(&curpath[i], "/\0", 2))
		{
			ft_memmove(&curpath[i], &curpath[i + 1]);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

t_bool	dot_handler(char *curpath)
{
	int i;

	i = 0;
	while (curpath[i])
	{
		if (!ft_strncmp(&curpath[i], "/./", 3)
		|| ft_strncmp(&curpath[i], "/.\0", 3))
		{
			ft_memmove(&curpath[i + 1], &curpath[i + 3]);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

t_bool	dot_dot_handler(char *curpath)
{
	int i;
	int pre;

	i = 0;
	pre = 0;
	while (curpath[i])
	{
		if (curpath[i] == '/')
			pre = i;
		if (!ft_strncmp(&curpath[i], "/../", 4)
		|| ft_strncmp(&curpath[i], "/..\0", 4))
		{
			ft_memmove(&curpath[pre + 1], &curpath[i + 4]);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

void	ft_bzero(char *s, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
		s[i++] = 0;
}