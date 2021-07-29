/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 22:07:21 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/29 22:07:40 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "exec.h"
#include "get_next_line.h"

int	main(int argc, char **argv, char **envp)
{
	char	*s;
	t_list	*list;

	list = init_list(argc, argv, envp);
	if (!list)
		return (free_list(list, "list malloc failed\n"));
	write(1, "prompt > ", 9);
	while (1)
	{
		if (!set_path(list))
			return (0);
		set_input_mode(list);
		if (!get_next_line(0, &s, list, 0))
			return (0);
		reset_input_mode(list);
		if (!parsing_start(s, list))
		{
			write(1, "prompt > ", 10);
			continue ;
		}
		snatch_error(exec(list), list);
		error_list_free("", list);
		write(1, "prompt > ", 10);
	}
	return (free_list(list, ""));
}
