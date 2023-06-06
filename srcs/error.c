#include "minishell.h"

int	ft_error(char *str, int fd, int exit_flag)
{
	ft_putstr_fd(str, fd);
	if (fd == 2)
		exit (1);
	exit (exit_flag);
}
