#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>

typedef struct s_shell
{
	char	**envp;         // Copy of environment variables
	char	*input_line;    // Raw input
	char	**args;         // Parsed args from input
	int		exit_code;      // $? value
	int		last_pid;       // Last child PID
	int		pipe_fd[2];     // Pipe file descriptors
	// add more later (tokens, redirections, flags...)
}	t_shell;

//executor
char	*find_cmd_path(char *cmd);
void	execute_command(t_shell *shell);

#endif