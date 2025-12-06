#include "../include/pipex_bonus.h"

void	init_multi_cmd(t_pipex *data, int argc, char **argv, char **envp)
{
	int	i;
	//int	signal;

	i = 0;
	data = ft_calloc(1, sizeof(t_pipex));
	if (!data)
	{
		// ft_error("Malloc failed", data);
	}
	data->nb_cmd = argc - 3;
	data->envp = envp;
	data->in_file = open_infile(argv[1], data);
	data->out_file = open_outfile(argv[argc - 1], data);
	data->cmd = ft_calloc(data->nb_cmd, sizeof(t_cmd));
	while (i < data->nb_cmd - 2) // check
	{
		if (!init_cmd(&data->cmd[i], argv[i + 2], envp, data))
		{
			ft_error("Command not vallid", data);
		}
		if (pipe(data->pipe_fd) < 0)
		{
			ft_error("Unable to pipe", data);
		}
		data->pid1 = fork();
		if (data->pid1 < 0)
		{
			ft_printf("ERRRRRRRRRRRRRROR");
			exit(EXIT_FAILURE);
		}
		if (data->pid1 == 0)
		{
			exec_cmd1(data, i);
		}
		data->in_file = data->pipe_fd[0];
		i++;
	}
	if (!init_cmd(&data->cmd[i], argv[i + 2], envp, data))
	{
		ft_error("Command not vallid", data);
	}
	if (pipe(data->pipe_fd) < 0)
	{
		ft_error("Unable to pipe", data);
	}
	data->pid2 = fork();
	if (data->pid2 < 0)
	{
		ft_printf("NTM");
	}
	if (data->pid2 == 0)
	{
		exec_cmd2(data, i);
	}
	//waitpid(data->pid2, &signal, 0);
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
	ft_memset(&data, 0, sizeof(data));
	init_multi_cmd(data, argc, argv, envp);
}
