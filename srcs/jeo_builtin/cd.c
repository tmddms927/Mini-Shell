#include "exec.h"
#include <limits.h>

int	cd(char *dir, char **envp)
{
// check dir operand
// if (operand == null)
//		check home path
//			if (home == null)
//				nothing
//			else
//				chdir(home)
//	else
//		check path
//		if (path == .)
//			dot_handler
//		else if (path == ..)
//			dot_dot_handler
// 		remove not needed slash 
//
//	chdir(curpath)
}

int	mv_home(char **envp)
{
	char	path[PATH_MAX];
	int		ret;

	getvalue(&path, envp, HOME);
	if (path)
		ret = chdir(path);
	return (ret);
}

char	*set_curpath(char *curpath, char *dir)
{
	if (*dir == '/')
		custom_strcpy(curpath, dir);
	else
		custom_strcpy(curpath, ft_strjoin(pwd(), dir));
	return (&curpath);
}

t_bool not_need_sl(char *curpath)
{
	int	i;

	i = 0;
	while (curpath[i])
	{
		if (!ft_strncmp(&curpath[i], "//", 2))
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
		if (!ft_strncmp(&curpath[i], "/./", 3))
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
		if (!ft_strncmp(&curpath[i], "/../", 4))
		{
			ft_memmove(&curpath[pre + 1], &curpath[i + 4]);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
