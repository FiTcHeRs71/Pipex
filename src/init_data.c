/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:22:36 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/09 14:23:24 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_pipex	*init_pipex(char **argv, char **envp, t_pipex *data)
{
	data = ft_calloc(1, sizeof(t_pipex));
	if (!data)
	{
		ft_error("Malloc failed", data);
	}
	data->envp = envp;
	data->in_file = open_infile(argv[1], data);
	data->out_file = open_outfile(argv[4], data);
	if (!init_cmd(&data->cmd1, argv[2], envp, data))
	{
		command_error("pipex : command not found : ", argv[2]);
	}
	if (!init_cmd(&data->cmd2, argv[3], envp, data))
	{
		command_error("pipex : command not found : ", argv[3]);
	}
	if (pipe(data->pipe_fd) < 0)
	{
		ft_error("Unable to pipe", data);
	}
	return (data);
}

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
		ft_error("No path available", data);
	path = ft_split(path_env, ':');
	if (!path)
		ft_error("Malloc Failed", data);
	size = ft_counter(path_env, ':');
	while (path[i])
	{
		result = try_path(path[i], cmd, data);
		if (result)
			return (ft_free_2d_array(path, size), result);
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
