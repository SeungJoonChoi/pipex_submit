#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
    t_pipex pipex;

    ft_bzero(&pipex, sizeof(t_pipex));
    if (argc < min_argc(&pipex, argv[1]))
        exit_with_msg("Invalid number of arguments.\n");
    if (pipex.heredoc)
        here_doc(&pipex, argc, argv);
    else
        openfile(&pipex, argc, argv);
    dup2(pipex.infile, STDIN_FILENO);
    dup2(pipex.outfile, STDOUT_FILENO);
    while (pipex.idx_cmd < pipex.last_cmd)
    {
        piping(argv[pipex.idx_cmd], envp);
        pipex.idx_cmd++;
    }
    if (pipex.heredoc)
        unlink(".heredoc_tmp");
    do_cmd(argv[pipex.last_cmd], envp);
}