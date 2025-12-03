
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
	int		fd[2];
	int		in_file;
	int		out_file;
	t_cmd	cmd1;
	t_cmd	cmd2;
	pid_t	pid1;
	pid_t	pid2;
	char	**envp;
}			t_pipex;

t_pipex		*init_pipex(char **argv, char **envp);
int			open_infile(char *infile);
int			open_outfile(char *outfile);
bool		init_cmd(t_cmd *cmd, char *cmd_str, char **envp);
char		**parse_command(char *cmd);
char		*find_path(char *cmd, char **envp);
char		*search_in_path(char *cmd, char **envp);
char		*get_path_envp(char **envp);
char	*try_path(char *envp, char *cmd);

#endif