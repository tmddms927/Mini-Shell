#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

extern char **environ;

int	main(void)
{
	char *str[4];
	//int fd;


	
	str[0] = "echo";
	str[1] = "-n";
	str[2] = "b";
	str[3] = 0;
	//dup2();
	//redir ->
	execve("/usr/bin/echo", str, environ);

	printf("error");
	return (0);
}
