/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seung-eun <seung-eun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:12:14 by seungoh           #+#    #+#             */
/*   Updated: 2021/07/26 21:37:59 by seung-eun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "header.h"
#include "exec.h"
#include "object.h"

static int g_sign = 0;

void	ctrl_c(int signo)
{
	(void)signo;

	g_sign = 1;
	// printf("\n");
	// rl_on_new_line();
	// write(0, "\r", 1);

	//rl_replace_line("", 0);
	//rl_redisplay();
}

int	main(int argc, char **argv, char **envp)
{
	char	*s;
	char	prompt[100] = "prompt > \0";
	t_list	*list;

	init_signal();
	list = init_list(argc, argv, envp);	
	if (!list)
		return (free_list(list, "list malloc failed\n"));
	while (1)
	{
		s = readline(prompt);
		if (g_sign)
		{
			g_sign = 0;
			free(s);
			continue ;
		}
		if (!s)
		{
			write(0, "\b \b\b \b", 6);
			printf("exit\n");
			exit(0);
		}
		add_history(s);
		if (!parsing_start(s, list))
		{
			free(s);
			continue ;
		}
		separate_stream(exec, list);
		//print_list(list);
		error_list_free("", list);
	}
	return (free_list(list, ""));
}

/*
** parsing main function
*/

int	parsing_start(char *s, t_list *list)
{
	t_words	*words;

	words = (t_words *)malloc(sizeof(t_words));
	if (!words)
		return (error_print("Error : failed malloc\n"));
	words->head = 0;
	if (!ft_split(words, s, list))
		return (0);
	if (!set_list(list, words))
	{
		free_list(list, "");
		return (0);
	}
	set_path_in_com(list);
	free_words(words, "");
	return (1);
}

int	set_list(t_list *list, t_words *words)
{
	t_word	*word;

	if (!com_oadd(list))
		return (0);
	word = words->head;
	while (word)
	{
		if (!set_command(list, word->s))
		{
			free_list(list, "");
			return (0);
		}
		word = word->next;
	}
	return (1);
}
