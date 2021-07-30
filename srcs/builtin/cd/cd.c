/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:06:52 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/30 16:06:53 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (set_curpath(curpath, dir, list))
		return (1);
	while (dot_handler(curpath))
		;
	while (not_need_sl(curpath))
		;
	while (dot_dot_handler(curpath))
		;
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

int	ft_pathjoin(char *dest, char *path, char *dir)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(path, "/");
	tmp2 = ft_strjoin(tmp, dir);
	if (!tmp || !tmp2)
		return (0);
	ft_memmove(dest, tmp2, ft_strlen(tmp2));
	free(tmp);
	free(tmp2);
	return (1);
}
