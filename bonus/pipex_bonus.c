/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:54:17 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/09 10:54:57 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	define_input(t_pipex *data)
{
	char	*line;
	int		pip_fd[2];

	if (pipe(pip_fd) == -1)
		ft_error("Unable to pipe", data);
	while (true)
	{
		ft_putstr_fd("heredoc > ", 1);
		line = get_next_line(0);
		if (!line)
		{
			break ;
		}
		if (ft_strncmp(line, data->limiter, ft_strlen(data->limiter)) == 0
			&& line[ft_strlen(data->limiter)] == '\n')
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, pip_fd[1]);
		free(line);
	}
	close(pip_fd[1]);
	data->in_file = pip_fd[0];
}

void	init_data_heredoc(t_pipex *data, char **argv, int argc, char **envp)
{
	data->nb_cmd = argc - 4;
	data->envp = envp;
	data->in_file = 0;
	data->out_file = open_outfile(argv[argc - 1], data);
	data->cmd = ft_calloc(data->nb_cmd, sizeof(t_cmd));
	if (!data->cmd)
	{
		ft_error("Malloc failed", data);
	}
	data->limiter = argv[2];
}

void	init_multi_cmd(t_pipex *data, int argc, char **argv, char **envp)
{
	int	i;

	i = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && ft_strlen(argv[1]) == 8)
	{
		init_data_heredoc(data, argv, argc, envp);
		define_input(data);
		while (i < data->nb_cmd)
		{
			if (!init_cmd(&data->cmd[i], argv[i + 3], envp, data))
				perror("Command invalid");
			i++;
		}
	}
	else
	{
		init_data(data, argv, argc, envp);
		while (i < data->nb_cmd)
		{
			if (!init_cmd(&data->cmd[i], argv[i + 2], envp, data))
				perror("Command invalid");
			i++;
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;

	if (argc < 5)
	{
		ft_putstr_fd("Use:./pipex_bonus here_doc LIMITER cmd1 cmd2..outfile\n",
			2);
		ft_putstr_fd("or : ./pipex_bonus infile cmd1 cmd2 ... outfile\n", 2);
		exit(EXIT_FAILURE);
	}
	data = ft_calloc(1, sizeof(t_pipex));
	if (!data)
	{
		ft_error("Malloc failed", data);
	}
	init_multi_cmd(data, argc, argv, envp);
	exec_cmd(data);
	ft_check_close(data);
	ft_free_struct(data);
	return (0);
}
