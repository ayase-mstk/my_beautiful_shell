#include "minishell.h"

int	ft_error(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	if (fd == 2)
		exit (1);
	exit (0);
}
