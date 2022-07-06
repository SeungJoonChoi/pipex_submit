#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
    t_pipex pipex;
    int i;

    ft_bzero(&pipex, sizeof(t_pipex));
    if (argc < min_argc(&pipex, argv[1]))
        exit_with_msg("Invalid number of arguments.\n");
    if (pipex.heredoc)
        here_doc(&pipex, argc, argv);
    else
        openfile(&pipex, argc, argv);
    pipex.child_pid = (int *)malloc(pipex.cmd_nmb * sizeof(int));
    if (pipex.child_pid == NULL)
        exit_with_msg("Memory allocation failed.\n");
    i = -1;
    while (++i < pipex.cmd_nmb)
        piping(&pipex, argv[2 + pipex.heredoc + i], envp, i);
    if (pipex.heredoc)
        unlink(".heredoc_tmp");
    i = -1;
    while (++i < pipex.cmd_nmb)
        waitpid(pipex.child_pid[i], NULL, 0);
    free(pipex.child_pid);
    return (0);
}