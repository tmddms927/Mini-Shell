/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 21:20:41 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/09 01:36:02 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_H
# define SPLIT_H

int				input_words(t_words *words, char *s, int len, int type);
void			put_char(char *s, char *c, int i);
int				words_oadd(t_words *words);
t_word			*words_olast(t_words *words);

#endif
