#include "pipex.h"

void exit_with_msg(char *err_msg)
{
    write(2, err_msg, ft_strlen(err_msg));
    exit(1);
}