#include "bipipe.h"

void		handle_error(char *str)
{
	printf("error : %s\n", str);
	exit(1);
}

void		handle_message(char *str)
{
	printf("message : %s\n", str);
}