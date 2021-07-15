// /*
// ** init_pipe()
// */

// #include "bipipe.h"
// #include <stdio.h>

// t_com *command_cat(char *file, char **env)
// {
// 	t_com *command_info;
// 	int argc;

// 	if (!(command_info = (t_com *)malloc(sizeof(t_com))))
// 		return (0);
// 	command_info->c = "cat";
// 	if (!(command_info->path = (char **)malloc(sizeof(char *) * 2)))
// 		return (0);
// 	command_info->path[0] = "/bin/cat";
// 	command_info->path[1] = 0;
// 	argc = 3;
// 	if (!(command_info->argv = (char **)malloc(sizeof(char *) * argc)))
// 		return (0);
// 	command_info->argv[0] = "cat";
// 	command_info->argv[1] = file;
// 	command_info->argv[argc - 1] = 0;
// 	command_info->re_head = 0;
// 	command_info->env = env;
// 	command_info->next = 0;
// 	return (command_info);
// }

// t_com *command_ls(char **env)
// {
// 	t_com *command_info;
// 	int argc;

// 	if (!(command_info = (t_com *)malloc(sizeof(t_com))))
// 		return (0);
// 	command_info->c = "ls";
// 	if (!(command_info->path = (char **)malloc(sizeof(char *) * 2)))
// 		return (0);
// 	command_info->path[0] = "/bin/ls";
// 	command_info->path[1] = 0;
// 	argc = 2;
// 	if (!(command_info->argv = (char **)malloc(sizeof(char *) * argc)))
// 		return (0);
// 	command_info->argv[0] = "ls";
// 	// command_info->argv[1] = file;
// 	command_info->argv[argc - 1] = 0;
// 	command_info->re_head = 0;
// 	command_info->env = env;
// 	command_info->next = 0;
// 	return (command_info);
// }

// t_com *command_grep(char **env)
// {
// 	t_com *command_info;
// 	int argc;

// 	if (!(command_info = (t_com *)malloc(sizeof(t_com))))
// 		return (0);
// 	command_info->c = "grep";
// 	if (!(command_info->path = (char **)malloc(sizeof(char *) * 2)))
// 		return (0);
// 	command_info->path[0] = "/usr/bin/grep";
// 	command_info->path[1] = 0;
// 	argc = 3;
// 	if (!(command_info->argv = (char **)malloc(sizeof(char *) * argc)))
// 		return (0);
// 	command_info->argv[0] = "grep";
// 	command_info->argv[1] = "pipe";
// 	command_info->argv[argc - 1] = 0;
// 	command_info->re_head = 0;
// 	command_info->env = env;
// 	command_info->next = 0;
// 	return (command_info);
// }

// int		main(int argc, char **argv, char **env)
// {
// 	// t_com *com = command_ls(env);
// 	t_com* com =command_cat("bipipe.c", env);
// 	// com->next =command_cat("hi", env);
// 	com->next =command_grep(env);
// 	// com->next->next = command_grep(env);
// 	exec(com);
// 	// int pipe_write[2];
// 	// int pipe_read[2];
// 	// int pid;
// 	// int rd_num;
// 	// char buf[BUFFERSIZE];

// 	// init_pipe(pipe_write, pipe_read);
// 	// pid = fork();
// 	// if (pid < 0)
// 	// 	handle_error("");
// 	// else if (pid == CHILD)
// 	// {
// 		// child_fir(command_ls(env),pipe_write, pipe_read);
// 		// int fd;

// 		// close(pipe_write[1]);
// 		// close(pipe_write[0]);
// 		// close(pipe_read[0]);
// 		// close(pipe_read[1]);
// 		// fd = open("hello", O_WRONLY | O_CREAT, 0755);
// 		// if (fd < 0)
// 		// 	handle_error("file doesn't open");
// 		// else
// 		// 	write(fd, "this is hello file.", 18);
// 		// close(fd);
// 	// }
// 	// else if (pid > CHILD)
// 	// {
// 		// parent_pipe_connect(pid, pipe_write, pipe_read);
// 		// waitpid(pid, NULL, 0);
// 		// exec_to_pipe(command_cat("hello", env), pipe_write, pipe_read);
// 		// rd_num = read(pipe_read[0], &buf, BUFFERSIZE);
// 		// write(2, &buf, rd_num);
// 		// printf("rd_num : %d, string : %s\n", rd_num, buf);
// 	// }
// 	return (0);
// }










