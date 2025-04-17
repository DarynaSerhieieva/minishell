#include <minishell.h>

static void	minishell_routin(t_shell *shell)
{

	while (1)
	{
		shell->input_line = readline("minishell > ");
		if (!shell->input_line)
		{
			printf("exit\n");
			break ;
		}
		if (*shell->input_line)
			add_history(shell->input_line);
		execute_command(shell);
		free(shell->input_line);
	}
}


int	main(void)
{
	t_shell	shell;


	ft_memset(&shell, 0, sizeof(t_shell));
	minishell_routin(&shell);
	return (0);
}
