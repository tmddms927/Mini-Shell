/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 21:20:41 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/28 22:47:59 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_H
# define SPLIT_H

int		input_words(t_words *words, char *s, int len, int type);
void	put_char(char *s, char *c, int i);
int		words_oadd(t_words *words);
t_word	*words_olast(t_words *words);
int		put_words4(t_pars *pars, char *s);
int		put_words5(t_pars *pars, char **s);
int		put_words6(t_pars *pars, char **s);
int		put_words7(t_pars *pars, char **s);
void	put_words8(t_pars *pars, char *s);

#endif
