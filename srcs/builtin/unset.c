/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 23:09:56 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/25 23:27:22 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "object.h"

int	unset(t_list *list, t_com *com)
{
	int i;

	i = 0;
	while (com->argv[++i])
		remove_set(list, com->argv[i]);
	return (1);
}
