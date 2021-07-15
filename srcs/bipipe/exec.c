#include "bipipe.h"
#include <stdio.h>

void		exec(t_list *command_list)
{
	t_com	*command_info;

	command_info = command_list->head;
	if (lst_len(command_info) > 1)
		exec_multy_command(command_info, command_list->envp);
	else
		command(command_info, command_list->envp);
}

void		exec_multy_command(t_com *command_info, char **envp)
{
	t_com *c_list;

	c_list = command_info;
	while (c_list)
	{
		if (c_list->next == 0)
			command_exit(c_list, envp);
		else
			command_out_pipe(c_list, envp);
		c_list = c_list->next;
	}
}

void		command(t_com *command_node, char **envp)
{
	//int ret;
    int i;

    i = 0;
	dprintf(2,"%s\n", envp[1]);
	//ret = 1;
	// redirect(command_node->re_head);
	// dprintf(2 ,"message : <command> \npath : %s\nargv[1] : %s\n", command_node->path[i], command_node->argv[1]);
	while ((command_node->path)[i] != 0)
	{
		dprintf(2,"%s\n", command_node->path[i]);
		execve(command_node->path[i], command_node->argv, envp);
		//ret = execve(command_node->path[i], command_node->argv, envp);
		i++;
		write(2, "hi", 2);
	}
	handle_error("excusion doesn't exist");
}

void		command_exit(t_com *command_node, char **envp)
{
	int		pid;

	pid = fork();
	if (pid < 0)
		handle_error("command_exit");
	else if (pid == CHILD)
		command(command_node, envp);
	// else if (pid > CHILD)
}

void		command_out_pipe(t_com *command_node, char **envp)
{
	int		pipefd[2];
	int		pid;

	pipe(pipefd);
	pid = fork();
	if (pid < 0)
		handle_error("command_out_pipe");
	else if (pid == CHILD)
	{
		close(pipefd[READ]);
		dup2(pipefd[WRITE], STDOUT_FILENO);
		close(pipefd[WRITE]);
		command(command_node, envp);
	}
	else if (pid > CHILD)
	{
		close(pipefd[WRITE]);
		dup2(pipefd[READ], STDIN_FILENO);
		close(pipefd[READ]);
	}
}