#include <minishell.h>

int	main(void)
{
	char	*rl;

	while (1)
	{
		rl = readline("minishell > ");
		if (!rl)
		{
			printf("exit\n");
			break ;
		}
		if (*rl)
			add_history(rl);
		execute_command(rl);
		free(rl);
	}
	return (0);
}
