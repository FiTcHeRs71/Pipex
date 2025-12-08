#include "../include/pipex_bonus.h"

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

void	close_file(t_pipex *data, int i)
{
	close(data->pipe_fd[1]);
	if (data->in_file > 0 && i > 0)
		close(data->in_file);
	data->in_file = data->pipe_fd[0];
}

void	ft_free_struct(t_pipex *data)
{
	int	i;

	i = 0;
	if (!data)
	{
		return ;
	}
	while (i < data->nb_cmd)
	{
		if (data && data->cmd[i].args)
		{
			ft_free_2d_arrayss(data->cmd[i].args);
		}
		if (data && data->cmd[i].path)
		{
			free(data->cmd[i].path);
		}
		i++;
	}
	free(data->cmd);
	free(data);
}
void	ft_check_close(t_pipex *data) // boucle sur data ?
{
	if (!data)
	{
		return ;
	}
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

void	ft_error(char *str, t_pipex *data)
{
	ft_putstr_fd(str, 2);
	ft_check_close(data);
	ft_free_struct(data);
	exit(EXIT_FAILURE);
}