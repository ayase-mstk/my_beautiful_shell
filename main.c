#include "minishell.h"

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
	printf("%s\n", av[0]);
	while (1)
	{
		line = readline("minishell$ ");
		if (line == NULL || ft_strlen(line) == 0)
		{
			free(line);
			break ;
		}
		child(line, env);
		add_history(line);
		free(line);
	}
	ft_printf("exit\n");
	return (0);
}
