
#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;

	if (argc != 5)
	{
		ft_putstr_fd("Error | Usage : ./pipex infile cmd1 cmd2 outfile\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_memset(&data, 0, sizeof(data));
	data = init_pipex(argv, envp, data);
	exec_pipline(data);
	close(data->out_file);
	ft_check_close(data);
	ft_free_struct(data);
	return (0);
}

// cree un fichier si il exite pas
// include ft_counter dans libft et maj split
// maj make file sur la compilation
// ft_putstr_fd("or: ./pipex here_doc LIMITER cmd1 cmd2 outfile\n", 2);
