#include "../include/pipex.h"

void	exec_pipline(t_pipex *data)
{
	int	signal;

	data->pid1 = fork();
	if (data->pid1 < 0)
	{
		ft_error("Fork failed", data);
	}
	if (data->pid1 == 0)
	{
		exec_cmd1(data);
	}
	close(data->pipe_fd[1]);
	close(data->in_file);
	data->pid2 = fork();
	if (data->pid2 < 0)
	{
		ft_error("Fork failed", data);
	}
	if (data->pid2 == 0)
	{
		exec_cmd2(data);
	}
	waitpid(data->pid1, &signal, 0);
	waitpid(data->pid2, &signal, 0); //check signal if -1 ?
}

void	exec_cmd1(t_pipex *data)
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
	if (execve(data->cmd1.path, data->cmd1.args, data->envp) < 0)
	{
		ft_error("execve failed", data);
		exit(EXIT_FAILURE);
	}
}

void	exec_cmd2(t_pipex *data)
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
	if (execve(data->cmd2.path, data->cmd2.args, data->envp) < 0)
	{
		ft_error("execve failed", data);
		exit(EXIT_FAILURE);
	}
}