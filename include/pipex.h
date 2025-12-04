
#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"

typedef struct s_cmd
{
	char	**args;
	char	*path;
}			t_cmd;

typedef struct s_pipex
{
	int		pipe_fd[2];
	int		in_file;
	int		out_file;
	t_cmd	cmd1;
	t_cmd	cmd2;
	pid_t	pid1;
	pid_t	pid2;
	char	**envp;
}			t_pipex;

// init_data.c
t_pipex		*init_pipex(char **argv, char **envp, t_pipex *data);
bool		init_cmd(t_cmd *cmd, char *cmd_str, char **envp, t_pipex *data);
char		**parse_command(char *cmd, t_pipex *data);
char		*search_in_path(char *cmd, char **envp, t_pipex *data);
char		*try_path(char *envp, char *cmd, t_pipex *data);

// init_data_utils.c
int			open_infile(char *infile, t_pipex *data);
int			open_outfile(char *outfile, t_pipex *data);
int			ft_counter(char *s, char c);
char		*find_path(char *cmd, char **envp, t_pipex *data);
char		*get_path_envp(char **envp);

// exec_pipe.c
void		exec_pipline(t_pipex *data);
void		exec_cmd1(t_pipex *data);
void		exec_cmd2(t_pipex *data);

// error_and_clear.c
void		ft_free_2d_arrayss(char **args);
void		ft_free_struct(t_pipex *data);
void		ft_error(char *str, t_pipex *data);

#endif