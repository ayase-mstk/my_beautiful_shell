#include "minishell.h"

void	sigint_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	set_sigaction(void)
{
	struct sigaction	sa;

	sa.sa_handler = sigint_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

void	get_command(char *line, char **env)
{
	char	*exactpath;

	exactpath = get_filepath(line, env);
	execve(exactpath, ft_split(line, ' '), env);
	exit(0);
}

void	child(char *line, char **env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
		get_command(line, env);
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (!WIFEXITED(status))
		{
			free(line);
			ft_error("child process error\n", 2);
		}
	}
	else
	{
		perror("fork");
		free(line);
		exit(1);
	}
}

int main(int ac, char **av, char **env)
{
	char	*line;

	if (ac != 1)
		return (0);
	set_sigaction();
	printf("%s\n", av[0]);
	while (1)
	{
		line = readline("minishell$ ");
		if (line == NULL || ft_strlen(line) == 0)
		{
			free(line);
			break ;
		}
		if (strlen(line) > 0)
			add_history(line);
		child(line, env);
		free(line);
	}
	ft_printf("minishell$ exit\n");
	return (0);
}
