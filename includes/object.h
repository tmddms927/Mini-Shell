/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:45:06 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/26 17:40:16 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

#include "header.h"

/*
** set object 
*/

int				set_oadd(t_list *list);
t_set			*set_olast(t_list *list);
t_set	*find_set(t_list *list, char *s);
void	remove_set(t_list *list, char *s);

/*
** word object
*/

int				words_oadd(t_words *words);
t_word			*words_olast(t_words *words);

/*
** com object
*/

int				com_oadd(t_list *list);
t_com			*com_oadd2(void);
t_com			*com_olast(t_list *list);

/*
** re object
*/

int	re_oadd(t_list *list);
t_re	*re_olast(t_list *list);

/*
** list object
*/

t_list			*init_list(int argc, char **argv, char **envp);

/*
** addenv object
*/

int	addenv_oadd(t_list *list);
t_addenv	*addenv_olast(t_list *list);
t_addenv	*find_addenv(t_list *list, char *s);
void	remove_addenv(t_list *list, char *s);

#endif