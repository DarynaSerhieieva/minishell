#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>

//executor
char	*find_cmd_path(char *cmd);
void	execute_command(char *input);

#endif