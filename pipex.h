#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pipex
{
    int heredoc;
    int infile;
    int outfile;
    int idx_cmd;
    int last_cmd;
} t_pipex;

#endif