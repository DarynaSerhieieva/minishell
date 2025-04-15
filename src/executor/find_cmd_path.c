#include <minishell.h>

static char	*build_full_path(char *dir, char *cmd)
{
	size_t	size;
	char	*full;

	size = ft_strlen(dir) + ft_strlen(cmd) + 2;
	full = malloc(size);
	if (!full)
	{
		perror("malloc failed");
		exit(ENOMEM);
	}
	ft_strlcpy(full, dir, size);
	ft_strlcat(full, "/", size);
	ft_strlcat(full, cmd, size);
	return (full);
}

char	*find_cmd_path(char *cmd)
{
	char	*path;
	char	**paths;
	char	*full;
	int		i;

	path = getenv("PATH");
	i = 0;
	if (!path || ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	paths = ft_split(path, ':');
	while (paths[i])
	{
		full = build_full_path(paths[i], cmd);
		if (access(full, X_OK) == 0)
		{
			ft_free_matrix((void **)paths);
			return (full);
		}
		free(full);
		i++;
	}
	ft_free_matrix((void **)paths);
	return (NULL);
}
