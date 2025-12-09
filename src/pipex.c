/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:46:25 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/09 13:46:25 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

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
