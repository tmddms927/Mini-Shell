/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 03:04:25 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/24 21:48:13 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "split.h"

static int	put_words3(t_pars *pars, t_list *list)
{
	printf("===>1 %s\n", pars->s);
	printf("===>2 %c\n", *(pars->s));
	printf("===>3 %d\n", pars->);
	if (*(pars->s) == '$' && pars->type != 2)
	{
		variable_in_set(pars, list);
		*(pars->s) = '!';
	}
	if (pars->type % 10 == 0 && *(pars->s) == '"')
	{
		pars->i++;
		pars->type = 1;
		*(pars->s) = 0;
		return (1);
	}
	else if (pars->type % 10 == 0 && *(pars->s) == '\'')
	{
		pars->i++;
		pars->type = 2;
		*(pars->s) = 0;
		return (1);
	}
	return (2);
}

static int	put_words2_2(t_words *words, t_pars *pars)
{
	int			val;

	val = put_words5(words, pars);
	if (val == 2)
	{
		val = put_words6(words, pars);
		if (val == 2)
		{
			val = put_words7(words, pars);
			if (val == 2)
				put_words8(pars);
		}
		else if (!val)
			return (0);
	}
	else if (!val)
		return (0);
	return (1);
}

static int	put_words2_1(t_words *words, t_pars *pars, t_list *list)
{
	int			val;

	val = put_words3(pars, list);
	if (val == 2)
	{
		val = put_words4(words, pars);
		if (val == 2)
		{
			if (!put_words2_2(words, pars))
				return (0);
		}
		else if (!val)
			return (0);
	}
	else if (!val)
		return (0);
	return (1);
}

/*
** 0 = X, 1 = ", 2 = '
*/

static int	put_words(t_words *words, char *s, t_list *list)
{
	t_pars	*pars;
	
	pars = (t_pars *)malloc(sizeof(t_pars));
	if (!pars)
		return (error_print("Error : failed malloc\n"));
	pars->type = 0;
	pars->i = 0;
	pars->orig_s = s;
	pars->s = s;
	while (pars->s)
	{
		if (!put_words2_1(words, pars, list))
			return (0);
		pars->s++;
	}
	if (pars->i > 0 && (pars->type == 1 || pars->type == 2))
		return (free_words(words, "Error : unclosed quotes\n"));
	if (pars->i > 0)
	{
		if (!input_words(words, s - pars->i, pars->i, pars->type))
			return (free_words(words, ""));
	}
	return (1);
}

/*
** split main function
*/

int	ft_split(t_words *words, char *s, t_list *list)
{	
	if (!s)
		return (free_words(words, ""));
	if (!put_words(words, s, list))
		return (0);

	
	
	// t_word *temp;
	// temp = words->head;
	// while (temp)
	// {
	// 	printf("%d, %s\n", temp->type, temp->s);
	// 	temp = temp->next;
	// }


	
	return (1);
}
