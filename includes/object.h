/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:45:06 by seung-eun         #+#    #+#             */
/*   Updated: 2021/07/29 15:58:37 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "header.h"

/*
** set object 
*/

int			set_oadd(t_list *list);
t_set		*set_olast(t_list *list);
t_set		*find_set(t_list *list, char *s);
void		remove_set(t_list *list, char *s);

/*
** word object
*/

int			words_oadd(t_words *words);
t_word		*words_olast(t_words *words);

/*
** com object
*/

int			com_oadd(t_list *list);
t_com		*com_oadd2(void);
t_com		*com_olast(t_list *list);

/*
** re object
*/

int			re_oadd(t_list *list);
t_re		*re_olast(t_list *list);

/*
** list object
*/

t_list		*init_list(int argc, char **argv, char **envp);

/*
** env object
*/

int			env_oadd(t_list *list);
t_env		*env_olast(t_list *list);
t_env		*find_env(t_list *list, char *s);
void		remove_env(t_list *list, char *s);

/*
** his object
*/

int			his_stack_oadd(t_list *list);
int			his_oadd(t_list *list, char *s);
t_his		*his_olast(t_list *list);

#endif