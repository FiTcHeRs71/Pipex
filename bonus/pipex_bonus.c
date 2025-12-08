#include "../include/pipex_bonus.h"

void	init_multi_cmd(t_pipex *data, int argc, char **argv, char **envp)
{
	int	i;

	i = 0;
	init_data(data, argv, argc, envp);
	while (i < data->nb_cmd)
	{
		if (!init_cmd(&data->cmd[i], argv[i + 2], envp, data))
		{
			ft_error("Command not vallid", data);
		}
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;

	if (argc < 5)
	{
		ft_putstr_fd("Error | Usage : ./pipex here_doc LIMITER cmd1 cmd2 ... outfile\n",
			2);
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
