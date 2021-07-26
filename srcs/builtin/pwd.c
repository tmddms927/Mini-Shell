#include "exec.h"
#include <limits.h>

int pwd(void)
{
    char path[PATH_MAX];

    getcwd(path, PATH_MAX);
    putstr(path, 1);
    putstr("\n", 1);
    return (0);
}