/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 21:20:41 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/23 15:37:52 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_H
# define SPLIT_H

int				input_words(t_words *words, char *s, int len, int type);
void			put_char(char *s, char *c, int i);
int				words_oadd(t_words *words);
t_word			*words_olast(t_words *words);
int	    put_words2(t_words *words, char *s, int *type, int *i);
int     put_words3(char *s, int *type, int *i);
int     put_words4(t_words *words, char *s, int *type, int *i);
int     put_words5(t_words *words, char **s, int *type, int *i);
int     put_words6(t_words *words, char **s, int *type, int *i);
int     put_words7(t_words *words, char *s, int *type, int *i);
void    put_words8(char *s, int *type, int *i);

#endif
