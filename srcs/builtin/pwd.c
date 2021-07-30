/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:07:02 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/30 16:07:03 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <limits.h>

int	pwd(void)
{
	char	path[PATH_MAX];

	getcwd(path, PATH_MAX);
	putstr(path, 1);
	putstr("\n", 1);
	return (0);
}
