#include "../include/pipex_bonus.h"

void	define_input(t_pipex *data) 
{
	char	*line;
	char	*temp;

	line = get_next_line(0); 
	temp = ft_strdup("");
	while (line)
	{
		temp = ft_strjoin(temp, line);
		if (ft_strncmp(line, data->limiter, ft_strlen(line)))
		{
			break;
		}
		free (line);
		line = get_next_line(0);
		ft_putstr_fd(temp, data->pipe_fd[0]);
	}
	free (line);
}

void	init_data_heredoc(t_pipex *data, char **argv, int argc, char **envp)
{
	data->nb_cmd = argc - 4;
	data->envp = envp;
	data->in_file = 0;
	data->out_file = open_outfile(argv[argc - 1], data);
	data->cmd = ft_calloc(data->nb_cmd, sizeof(t_cmd));
	data->limiter = argv[2];
}

void	init_multi_cmd(t_pipex *data, int argc, char **argv, char **envp)
{
	int		i;

	i = 0;
	if (ft_strncmp(argv[1], "here_doc", 9))
	{
		define_input(data);
		init_data_heredoc(data, argv, argc, envp);
	}
	else
	{
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
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;

	if (argc < 5)
	{
		ft_putstr_fd("Error | Usage : ./pipex_bonus here_doc LIMITER cmd1 cmd2 ... outfile\n",2);
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
