#include "../include/pipex.h"

void	ft_free_2d_arrayss(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	ft_free_struct(t_pipex *data)
{
	if (data && data->cmd1.args)
	{
		ft_free_2d_arrayss(data->cmd1.args);
	}
	if (data && data->cmd1.path)
	{
		free(data->cmd1.path);
	}
	if (data && data->cmd2.args)
	{
		ft_free_2d_arrayss(data->cmd2.args);
	}
	if (data && data->cmd2.path)
	{
		free(data->cmd2.path);
	}
	free(data);
}

void	ft_error(char *str, t_pipex *data)
{
	ft_putstr_fd(str, 2);
	ft_check_close(data);
	ft_free_struct(data);
	exit(EXIT_FAILURE);
}

void	ft_check_close(t_pipex *data)
{
	if (data && data->in_file > 0)
	{
		close(data->in_file);
	}
	if (data && data->out_file > 0)
	{
		close(data->out_file);
	}
	if (data && data->pipe_fd[0] > 0)
	{
		close(data->pipe_fd[0]);
	}
	if (data && data->pipe_fd[1] > 0)
	{
		close(data->pipe_fd[1]);
	}
}