/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:05:55 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/09 14:07:39 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	exec_cmd(t_pipex *data)
{
	int	i;

	i = 0;
	while (i < data->nb_cmd)
	{
		if (i < data->nb_cmd - 1)
		{
			if (pipe(data->pipe_fd) < 0)
				ft_error("Unable to pipe", data);
		}
		data->pid1 = fork();
		if (data->pid1 < 0)
			ft_error("Fork failed", data);
		if (data->pid1 == 0)
			handle_child_process(data, i, (i == data->nb_cmd - 1));
		if (i < data->nb_cmd - 1)
			close_file(data);
		i++;
	}
	i = 0;
	while (i < data->nb_cmd)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
}

void	handle_child_process(t_pipex *data, int i, int is_last)
{
	if (is_last)
		exec_cmd2(data, i);
	else
		exec_cmd1(data, i);
}

void	exec_cmd1(t_pipex *data, int i)
{
	if (data->in_file >= 0)
	{
		if (dup2(data->in_file, STDIN_FILENO) < 0)
		{
			perror("dup2 on infile for cmd1");
		}
	}
	close(data->in_file);
	if (dup2(data->pipe_fd[1], STDOUT_FILENO) < 0)
	{
		perror("dup2 on outfile for cmd1");
		exit(1);
	}
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	if (!data->cmd[i].path)
	{
		ft_error("No path", data);
	}
	if (execve(data->cmd[i].path, data->cmd[i].args, data->envp) < 0)
	{
		ft_error("execve failed", data);
	}
}

void	exec_cmd2(t_pipex *data, int i)
{
	if (data->in_file >= 0)
	{
		if (dup2(data->in_file, STDIN_FILENO) < 0)
		{
			ft_error("dup2 on infile for cmd2", data);
		}
	}
	if (dup2(data->out_file, STDOUT_FILENO) < 0)
	{
		ft_error("dup2 on infile for cmd2", data);
	}
	if (data->pipe_fd[0] > 0)
		close(data->pipe_fd[0]);
	if (data->pipe_fd[1] > 0)
		close(data->pipe_fd[1]);
	if (!data->cmd[i].path)
	{
		ft_error("No path", data);
	}
	if (execve(data->cmd[i].path, data->cmd[i].args, data->envp) < 0)
	{
		ft_error("execve failed", data);
	}
}
