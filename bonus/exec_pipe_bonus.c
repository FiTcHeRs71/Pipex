#include "../include/pipex_bonus.h"

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
	if (execve(data->cmd[i].path, data->cmd[i].args, data->envp) < 0)
	{
		ft_error("execve failed", data);
		exit(EXIT_FAILURE);
	}
}

void	exec_cmd2(t_pipex *data, int i)
{
	if (dup2(data->pipe_fd[0], STDIN_FILENO) < 0)
	{
		ft_error("dup2 on infile for cmd2", data);
	}
	if (dup2(data->out_file, STDOUT_FILENO) < 0)
	{
		ft_error("dup2 on infile for cmd2", data);
	}
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	if (execve(data->cmd[i].path, data->cmd[i].args, data->envp) < 0)
	{
		ft_error("execve failed", data);
		exit(EXIT_FAILURE);
	}
}