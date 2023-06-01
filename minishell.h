#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include <sys/wait.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include "libftprintf/ft_printf.h"

# define PATH "PATH="

char	*get_filepath(char *cmd, char **env);
int		ft_error(char *str, int fd);

#endif