
#include "../include/pipex.h"
#include <sys/types.h>
#include <sys/wait.h>

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;
	t_cmd	*cmd;

	if (argc != 5)
	{
		ft_putstr_fd("Error | Usage : ./pipex infile cmd1 cmd2 outfile\n", 2);
		// ft_putstr_fd("or: ./pipex here_doc LIMITER cmd1 cmd2 outfile\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_memset(&data, 0, sizeof(data));
	ft_memset(&cmd, 0, sizeof(cmd));
	data = init_pipex(argv, envp, data);
	exec_pipline(data);
	close(data->out_file);
	ft_free_struct(data);
	return (0);
}

// ============== EXEC PIPE =======================

void	exec_pipline(t_pipex *data)
{
	int	signal;

	data->pid1 = fork();
	if (data->pid1 < 0)
	{
		ft_error("Fork failed", data);
	}
	else if (data->pid1 > 0)
	{
		exec_cmd1(data);
	}
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	close(data->in_file);
	data->pid2 = fork();
	if (data->pid1 < 0)
	{
		ft_error("Fork failed", data);
	}
	else if (data->pid2 > 0)
	{
		exec_cmd2(data);
	}
	waitpid(data->pid1, &signal, 0);
	waitpid(data->pid2, &signal, 0);
}

void	exec_cmd1(t_pipex *data)
{
	if (data->in_file >= 0)
	{
		if (dup2(data->in_file, STDIN_FILENO) < 0)
		{
			ft_error("??", data);
		}
	}
	close(data->in_file);
	if (dup2(data->pipe_fd[1], STDOUT_FILENO) < 0)
	{
		ft_error("??", data);
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
		ft_error("????", data);
	}
	if (dup2(data->out_file, STDOUT_FILENO) < 0)
	{
		ft_error("??", data);
	}
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	if (execve(data->cmd2.path, data->cmd2.args, data->envp) < 0)
	{
		ft_error("execve failed", data);
		exit(EXIT_FAILURE);
	}
}

//=================== INIT DATA STRUCT =============
t_pipex	*init_pipex(char **argv, char **envp, t_pipex *data)
{
	data = ft_calloc(1, sizeof(t_pipex));
	if (!data)
	{
		ft_error("Malloc failed", data);
	}
	data->envp = envp;
	data->in_file = open_infile(argv[1], data);
	data->out_file = open_outfile(argv[4], data);
	if (!init_cmd(&data->cmd1, argv[2], envp))
	{
		ft_error("Command 1 not vallid", data);
	}
	if (!init_cmd(&data->cmd2, argv[3], envp))
	{
		ft_error("Command 2 not valid", data);
	}
	if (pipe(data->pipe_fd) < 0)
	{
		ft_error("Unable to pipe", data);
	}
	return (data);
}

int	open_infile(char *infile, t_pipex *data)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
	{
		ft_error("Unable to access infile", data);
	}
	return (fd);
}

int	open_outfile(char *outfile, t_pipex *data)
{
	int	fd;

	fd = open(outfile, O_WRONLY, O_CREAT, O_TRUNC);
	if (fd < 0)
	{
		ft_error("Unable to access or create outfile", data);
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
		exit(EXIT_FAILURE); // free ?
	}
	return (args);
}
char	*find_path(char *cmd, char **envp)
{
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
		{
			return (ft_strdup(cmd));
		}
		return (NULL);
	}
	else
	{
		return (search_in_path(cmd, envp));
	}
}

int	ft_counter(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		count++;
		while ((s[i] && s[i] != c))
			i++;
	}
	return (count);
}

char	*search_in_path(char *cmd, char **envp)
{
	char	**path;
	char	*path_env;
	char	*result;
	int		size;
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
		// ft_error("Malloc failed")
	}
	size = ft_counter(path_env, ':');
	while (path[i])
	{
		result = try_path(path[i], cmd);
		if (result)
		{
			ft_free_2d_array(path, size + 1);
			return (result);
		}
		free(result);
		i++;
	}
	ft_free_2d_array(path, i);
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
			return (envp[i] + 5);
		}
		i++;
	}
	return (NULL);
}

char	*try_path(char *envp, char *cmd)
{
	char *temp;
	char *temp2;

	temp = ft_strjoin(envp, "/");
	if (!temp)
	{
		exit(EXIT_FAILURE); // free ?
	}
	temp2 = ft_strjoin(temp, cmd);
	free(temp);
	if (!temp2)
	{
		exit(EXIT_FAILURE); // free ?
	}
	if (access(temp2, X_OK) == 0)
	{
		return (temp2); // a free
	}
	free(temp2);
	return (NULL);
}