/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:31:11 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/09 13:31:28 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	open_infile(char *infile, t_pipex *data)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
	{
		ft_error("Unable to access infile", data);
	}
	return (fd);
}

int	open_outfile(char *outfile, t_pipex *data)
{
	int	fd;

	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_error("Unable to access or create outfile", data);
	}
	return (fd);
}

int	ft_counter(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		count++;
		while ((s[i] && s[i] != c))
			i++;
	}
	return (count);
}

char	*find_path(char *cmd, char **envp, t_pipex *data)
{
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
		{
			return (ft_strdup(cmd));
		}
		return (NULL);
	}
	else
	{
		return (search_in_path(cmd, envp, data));
	}
}

char	*get_path_envp(char **envp)
{
	size_t	i;

	i = 0;
	if (!envp)
	{
		return (NULL);
	}
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			return (envp[i] + 5);
		}
		i++;
	}
	return (NULL);
}
