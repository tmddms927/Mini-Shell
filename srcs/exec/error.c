#include "exec.h"
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>

void	handle_error(char *str)
{
	printf("error : %s\n", str);
	exit(1);
}

void	handle_message(char *str)
{
	printf("message : %s\n", str);
}

void	snatch_error(int error_num)
{
	if (error_num)
		printf("snatch %d\n", error_num);
}

void	exit_safe(char *func_name, char *obj, int err_num, int exit_num)
{
	if (err_num < 108)
		printf("%s: %s: %s\n", func_name, obj, strerror(err_num));
	else if (err_num == 127)
		command_not_found(func_name, obj);
	exit(exit_num);
}

void	command_not_found(char *func_name, char *obj)
{
	printf("%s: %s: command not found\n", func_name, obj);
}
