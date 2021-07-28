#include "exec.h"
#include "object.h"
#include <limits.h>
#include <errno.h>

int	cd(t_list *list, char **argv)
{
	char	*dir;
	char	curpath[PATH_MAX];
	int		ret;

	dir = argv[1];
	ft_bzero(curpath, PATH_MAX);
	if (!dir)
		return (mv_home(list));
	set_curpath(curpath, dir);
	while (not_need_sl(curpath))
		write(2, "A", 1);
	while (dot_handler(curpath))
		write(2, "B", 1);
	while (dot_dot_handler(curpath))
		write(2, "C", 1);
	ret = chdir(curpath);
	if (ret)
		return (return_error("minishell", "cd", errno, 1));
	return (0);
}

int	mv_home(t_list *list)
{
	char	path[PATH_MAX];
	int		ret;

	ft_bzero(path, PATH_MAX);
	if (get_home(path, list))
	{
		if (*path)
		{
			ret = chdir(path);
			if (ret)
				return (return_error("minishell", "cd", errno, 1));
		}
	}
	return (0);
}
