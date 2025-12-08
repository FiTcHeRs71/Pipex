#include "../include/pipex_bonus.h"

bool	init_cmd(t_cmd *cmd, char *cmd_str, char **envp, t_pipex *data)
{
	cmd->args = parse_command(cmd_str, data);
	if (!cmd->args)
	{
		return (false);
	}
	cmd->path = find_path(cmd->args[0], envp, data);
	if (!cmd->path)
	{
		return (false);
	}
	return (true);
}

char	**parse_command(char *cmd, t_pipex *data)
{
	char	**args;
	char	*temp;
	size_t	i;

	i = 0;
	args = ft_split(cmd, ' ');
	if (!args)
	{
		ft_error("Malloc Failed", data);
	}
	while (args[i])
	{
		temp = ft_strtrim(args[i], "'");
		free(args[i]);
		args[i] = temp;
		i++;
	}
	return (args);
}

char	*search_in_path(char *cmd, char **envp, t_pipex *data)
{
	char	**path;
	char	*path_env;
	char	*result;
	int		size;
	size_t	i;

	i = 0;
	path_env = get_path_envp(envp);
	if (!path_env)
	{
		ft_error("No path available", data);
	}
	path = ft_split(path_env, ':');
	if (!path)
	{
		ft_error("Malloc Failed", data);
	}
	size = ft_counter(path_env, ':');
	while (path[i])
	{
		result = try_path(path[i], cmd, data);
		if (result)
		{
			ft_free_2d_array(path, size);
			return (result);
		}
		free(result);
		i++;
	}
	ft_free_2d_array(path, size);
	return (NULL);
}

char	*try_path(char *envp, char *cmd, t_pipex *data)
{
	char	*temp;
	char	*temp2;

	temp = ft_strjoin(envp, "/");
	if (!temp)
	{
		ft_error("Malloc Failed", data);
	}
	temp2 = ft_strjoin(temp, cmd);
	free(temp);
	if (!temp2)
	{
		ft_error("Malloc Failed", data);
	}
	if (access(temp2, X_OK) == 0)
	{
		return (temp2);
	}
	free(temp2);
	return (NULL);
}

void	init_data(t_pipex *data, char **argv, int argc, char **envp)
{
	data->nb_cmd = argc - 3;
	data->envp = envp;
	data->in_file = open_infile(argv[1], data);
	data->out_file = open_outfile(argv[argc - 1], data);
	data->cmd = ft_calloc(data->nb_cmd, sizeof(t_cmd));
}