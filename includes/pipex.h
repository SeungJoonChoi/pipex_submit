#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct s_pipex
{
    int heredoc;
    int infile;
    int outfile;
    int idx_cmd;
    int last_cmd;
} t_pipex;

//openfile
void here_doc(t_pipex *pipex, int argc, char **argv);
void openfile(t_pipex *pipex, int argc, char **argv);
//utils
int min_argc(t_pipex *pipex, char *arg);
void do_cmd(char *cmd, char **envp);
void piping(char *cmd, char *envp[]);
//error
void exit_with_msg(char *err_msg);
//get_next_line
char	*get_next_line(int fd);

#endif