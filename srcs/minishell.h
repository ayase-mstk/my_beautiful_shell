#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include "../libft/srcs/libft.h"
# include "../libftprintf/srcs/ft_printf.h"

# define PATH "PATH="

char	*get_filepath(char *cmd, char **env);
int		ft_error(char *str, int fd, int exit_flag);

#endif