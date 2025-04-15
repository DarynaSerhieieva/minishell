#include <minishell.h>

extern char	**environ;

void	execute_command(char *input)
{
	char	**args;
	char	*cmd_path;
	pid_t	pid;

	args = ft_split(input, ' ');
	if (!args || !args[0])
		return ;
	cmd_path = find_cmd_path(args[0]);
	if (!cmd_path)
	{
		printf("%s: command not found\n", args[0]);
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		execve(cmd_path, args, environ);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	free(cmd_path);
	ft_free_matrix((void **)args);
}
