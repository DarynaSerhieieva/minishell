#include <minishell.h>

extern char	**environ;

static void	fork_routine(char *cmd_path, t_shell *shell)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(cmd_path, shell->args, environ);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
}

void	execute_command(t_shell *shell)
{
	char	*cmd_path;

	shell->args = ft_split(shell->input_line, ' ');
	if (!shell->args || !shell->args[0])
		return ;
	cmd_path = find_cmd_path(shell->args[0]);
	if (!cmd_path)
	{
		printf("%s: command not found\n", shell->args[0]);
		return ;
	}
	fork_routine(cmd_path, shell);
	free(cmd_path);
	ft_free_matrix((void **)shell->args);
}
