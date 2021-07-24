#include "exec.h"
#include <fcntl.h>

void	find_tty(void)
{
	int		fd2;

	if (!isatty(STDIN_FILENO))
	{
		fd2 = open(ttyname(2), O_RDWR | O_TRUNC);
		dup2(fd2, STDIN_FILENO);
	}
}