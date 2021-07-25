#include "exec.h"

int	lst_len(t_com *command)
{
	t_com	*tmp;
	int		ret;

	tmp = command;
	if (!tmp)
		return (0);
	else
		ret = 1;
	while (tmp->next)
	{
		ret++;
		tmp = tmp->next;
	}
	return (ret);
}
