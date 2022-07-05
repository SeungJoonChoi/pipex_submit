#include "pipex.h"

int min_argc(t_pipex *pipex, char *arg)
{
    if (arg && !ft_strncmp(arg, "here_doc", ft_strlen("here_doc")))
    {
        pipex->heredoc++;
        return (6);
    }
    else
        return (5);
}

static char *path_join(char const *dir, char const *cmd)
{
	char	*str;
	char	*ret;

    if (dir == NULL)
        return (NULL);
	str = (char *)malloc((ft_strlen(dir) + ft_strlen(cmd) + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ret = str;
	while (*dir != '\0')
	{
		*str = *dir;
		str++;
		dir++;
	}
    *str = '/';
    str++;
	while (*cmd != '\0')
	{
		*str = *cmd;
		str++;
		cmd++;
	}
	*str = '\0';
	return (ret);
}

static char *pathfinder(char *cmd, char **envp)
{
    char *path;
    char *dir;
    char *bin;
    int i;

    i = 0;
    while (envp[i] && ft_strncmp(envp[i], "PATH=", ft_strlen("PATH=")))
        i++;
    if (envp[i] == NULL)
        return (NULL);
    path = envp[i] + ft_strlen("PATH=");
    while (path && ft_strchr(path, ':') != NULL)
    {
        dir = ft_substr(path, 0, ft_strchr(path, ':') - path);
        bin = path_join(dir, cmd);
        free(dir);
        if (access(bin, F_OK) == 0)
            return (bin);
        free(bin);
        path = ft_strchr(path, ':') + 1;
    }
    return (NULL);
}

void do_cmd(char *cmd, char **envp)
{
    char **argv;
    char *path;

    argv = ft_split(cmd, ' ');
    if (argv == NULL)
        return ;
    if (ft_strchr(argv[0], '/') == NULL)
        path = pathfinder(argv[0], envp);
    else
        path = argv[0];
    if (access(path, F_OK) != 0)
        exit_with_msg("Command not found.\n");
    execve(path, argv, envp);
    write(2, "Failed to execute ", 18);
    exit_with_msg(cmd);
}

void piping(char *cmd, char *envp[])
{
    pid_t pid;
    int fd[2];

    if (pipe(fd) != 0)
        exit_with_msg("Failed to creat pipe.\n");
    pid = fork();
    if (pid == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        do_cmd(cmd, envp);
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        waitpid(pid, NULL, 0);
    }
}