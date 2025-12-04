
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

t_pipex		*init_pipex(char **argv, char **envp, t_pipex *data);
int			open_infile(char *infile, t_pipex *data);
int			open_outfile(char *outfile, t_pipex *data);
bool		init_cmd(t_cmd *cmd, char *cmd_str, char **envp);
char		**parse_command(char *cmd);
char		*find_path(char *cmd, char **envp);
char		*search_in_path(char *cmd, char **envp);
char		*get_path_envp(char **envp);
char		*try_path(char *envp, char *cmd);
void		exec_pipline(t_pipex *data);
void		exec_cmd1(t_pipex *data);
void		exec_cmd2(t_pipex *data);
void		ft_error(char *str, t_pipex *data);
void		ft_free_struct(t_pipex *data);

#endif