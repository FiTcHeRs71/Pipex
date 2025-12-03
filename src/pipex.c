
#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;

	if (argc != 5)
	{
		ft_putstr_fd("Error | Usage : ./pipex infile cmd1 cmd2 outfile\n", 2);
		// ft_putstr_fd("or: ./pipex here_doc LIMITER cmd1 cmd2 outfile\n", 2);
		exit(EXIT_FAILURE);
	}
	data = init_pipex(argv, envp);
}

t_pipex	*init_pipex(char **argv, char **envp)
{
	t_pipex	*data;

	data = ft_calloc(1, sizeof(t_pipex));
	if (!data)
	{
		return (NULL);
	}
	data->envp = envp;
	data->in_file = open_infile(argv[1]);
	data->out_file = open_outfile(argv[4]);
	if (!init_cmd(&data->cmd1, argv[2], envp))
	{
		//free
		return (NULL);
	}
	if (!init_cmd(&data->cmd2, argv[3], envp))
	{
		//free;
		return (NULL);
	}
	if (pipe(data->p))
	return (data);
}

int	open_infile(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
	{
		// ft_error , free ?
		ft_putstr_fd("Unable to access infile", 2);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	open_outfile(char *outfile)
{
	int fd;
	fd = open(outfile, O_WRONLY, O_CREAT, O_TRUNC);
	if (fd < 0)
	{
		// ft_error , free ?
		ft_putstr_fd("Unable to access or create outfile", 2);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

bool	init_cmd(t_cmd *cmd, char *cmd_str, char **envp)
{
	cmd->args = parse_command(cmd_str);
	if (!cmd->args)
	{
		return (false);
	}
	cmd->path = find_path(cmd->args[0], envp);
	if (!cmd->path)
	{
		return (false);
	}
	return (true);
}

char	**parse_command(char *cmd)
{
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args)
	{
		ft_putstr_fd("Error : Malloc Failed", 2);
		exit (EXIT_FAILURE); //free ?
	}
	return (args);
}
char	*find_path(char *cmd, char **envp)
{
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
		{
			return(ft_strdup(cmd));
		}
		return (NULL);
	}
	else
	{
		return (search_in_path(cmd, envp));
	}
}

char	*search_in_path(char *cmd, char **envp)
{
	char	**path;
	char	*path_env;
	char	*result;
	size_t	i;

	i = 0;
	path_env = get_path_envp(envp);
	if (!path_env)
	{
		exit(EXIT_FAILURE); // free ?
	}
	path = ft_split(path_env, ':');
	if (!path)
	{
		exit(EXIT_FAILURE); //free ?
	}
	while (path[i])
	{
		result = try_path(path[i], cmd);
		if (result)
		{
			//free array path
			return(result);
		}
		i++;
	}
	//free array path
	return (NULL);
	
}
char	*get_path_envp(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			return(envp[i] + 5);
		}
		i++;
	}
	return (NULL);
}

char	*try_path(char *envp, char *cmd)
{
	char *temp;

	temp = ft_strjoin(envp,"/");
	if (!temp)
	{
		exit(EXIT_FAILURE); // free ?
	}
	temp = ft_strjoin(temp, cmd);
	if (!temp)
	{
		exit(EXIT_FAILURE); //free ?
	}
	if (access(temp, X_OK) == 0)
	{
		return (temp); //a free 
	}
	free(temp);
	return (NULL);
}