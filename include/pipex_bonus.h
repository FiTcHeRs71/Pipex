/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 05/12/2025 13:30:30 by fducrot           #+#    #+#             */
/*   Updated: 09/12/2025 10:50:41 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/include/libft.h"

typedef struct s_cmd
{
	char	**args;
	char	*path;
}			t_cmd;

typedef struct s_pipex
{
	int		pipe_fd[2];
	char	*limiter;
	char	**term_input;
	int		in_file;
	int		out_file;
	int		nb_cmd;
	t_cmd	*cmd;
	pid_t	pid1;
	pid_t	pid2;
	char	**envp;
}			t_pipex;

// error_and_clear_bonus.c
void		ft_free_2d_arrayss(char **args);
void		ft_check_close(t_pipex *data);
void		ft_free_struct(t_pipex *data);
void		ft_error(char *str, t_pipex *data);
void		close_file(t_pipex *data);

// exec pipe_bonus.c
void		exec_cmd1(t_pipex *data, int i);
void		exec_cmd2(t_pipex *data, int i);
void		handle_child_process(t_pipex *data, int i, int is_last);
void		exec_cmd(t_pipex *data);

// init_data_bonus.c
bool		init_cmd(t_cmd *cmd, char *cmd_str, char **envp, t_pipex *data);
char		**parse_command(char *cmd, t_pipex *data);
char		*search_in_path(char *cmd, char **envp, t_pipex *data);
char		*try_path(char *envp, char *cmd, t_pipex *data);
void		init_data(t_pipex *data, char **argv, int argc, char **envp);

// init_data_utils_bonus.c
int			open_infile(char *infile, t_pipex *data);
int			open_outfile(char *outfile, t_pipex *data);
int			ft_counter(char *s, char c);
char		*find_path(char *cmd, char **envp, t_pipex *data);
char		*get_path_envp(char **envp);

#endif