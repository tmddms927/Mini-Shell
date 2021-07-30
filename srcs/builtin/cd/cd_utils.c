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
	printf("minishell: cd: HOME not set");
	return (FALSE);
}

int	set_curpath(char *curpath, char *dir, t_list *list)
{
	char	path[PATH_MAX];
	int		len;
	char	tmp_path[PATH_MAX];

	if (!getcwd(path, PATH_MAX))
		return (return_error("minishell", "cd", errno, 1));
	if (!ft_strncmp(dir, "~/", 2) || !ft_strncmp(dir, "~\0", 2))
	{
		ft_bzero(path, PATH_MAX);
		if (!get_home(path, list))
			return (1);
	}
	if (*dir == '/')
		ft_memmove(curpath, dir, ft_strlen(dir));
	else
	{
		len = ft_strlen(path) + ft_strlen(dir) + 1;
		if (!ft_pathjoin(tmp_path, path, dir))
			return (1);
		ft_memmove(curpath, tmp_path, len);
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
			ft_memmove(&curpath[i], &curpath[i + 1],
				ft_strlen(&curpath[i + 1]) + 1);
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
			|| !ft_strncmp(&curpath[i], "/~/", 3)
			|| !ft_strncmp(&curpath[i], "/~\0", 3)
			|| !ft_strncmp(&curpath[i], "/.\0", 3))
		{
			ft_memmove(&curpath[i + 1], &curpath[i + 2],
				ft_strlen(&curpath[i + 2]) + 1);
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
		if (!ft_strncmp(&curpath[i], "/../", 4)
			|| !ft_strncmp(&curpath[i], "/..\0", 4))
		{
			ft_memmove(&curpath[pre + 1], &curpath[i + 4],
				ft_strlen(&curpath[i + 4]) + 1);
			ft_bzero(curpath + ft_strlen(curpath) + 1,
				PATH_MAX - ft_strlen(curpath) - 1);
			return (TRUE);
		}
		if (curpath[i] == '/')
			pre = i;
		i++;
	}
	return (FALSE);
}
