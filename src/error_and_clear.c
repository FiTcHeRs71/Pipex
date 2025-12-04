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
	if (data->cmd1.args)
	{
		ft_free_2d_arrayss(data->cmd1.args);
	}
	if (data->cmd1.path)
	{
		free(data->cmd1.path);
	}
	if (data->cmd2.args)
	{
		ft_free_2d_arrayss(data->cmd2.args);
	}
	if (data->cmd2.path)
	{
		free(data->cmd2.path);
	}
	free(data);
}

void	ft_error(char *str, t_pipex *data)
{
	ft_free_struct(data);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}