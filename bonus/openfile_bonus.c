#include "pipex_bonus.h"

static void make_temp(char *limiter)
{
    int temp_file;
    char *cmp;
    char *buf;

    temp_file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    cmp = ft_strjoin(limiter, "\n");
    if (cmp == NULL)
        exit_with_msg("Memory allocation failed.\n");
    while(1)
    {
        write(1, ">", 1);
        buf = get_next_line(0);
        if (buf == NULL)
        {
            free(cmp);
            exit_with_msg("Can't get next line.\n");
        }
        if (!ft_strncmp(cmp, buf, ft_strlen(buf) + 1))
            break ;
        write(temp_file, buf, ft_strlen(buf));
        free(buf);
    }
    free(buf);
    free(cmp);
    close(temp_file);
}

void here_doc(t_pipex *pipex, int argc, char **argv)
{
    pipex->idx_cmd = 3;
    pipex->last_cmd = argc - 2;
    make_temp(argv[2]);
    pipex->infile = open(".heredoc_tmp", O_RDONLY);
    if (pipex->infile < 0)
    {
        unlink(".heredoc_tmp");
        exit_with_msg("Failed to open file.\n");
    }
    pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (pipex->outfile < 0)
        exit_with_msg("Failed to open file.\n");
}

void openfile(t_pipex *pipex, int argc, char **argv)
{
    pipex->idx_cmd = 2;
    pipex->last_cmd = argc - 2;
    pipex->infile = open(argv[1], O_RDONLY);
    if (pipex->infile < 0)
        exit_with_msg("Failed to open file.\n");
    pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (pipex->outfile < 0)
        exit_with_msg("Failed to open file.\n");
}