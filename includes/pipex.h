/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjoon <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:54:54 by seungjoon         #+#    #+#             */
/*   Updated: 2022/07/06 20:55:40 by seungjoon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct s_pipex
{
	int	heredoc;
	int	infile;
	int	outfile;
	int	cmd_nmb;
	int	*child_pid;
}	t_pipex;

//openfile
void	here_doc(t_pipex *pipex, int argc, char **argv);
void	openfile(t_pipex *pipex, int argc, char **argv);
//utils
int		min_argc(t_pipex *pipex, char *arg);
void	do_cmd(char *cmd, char **envp);
void	piping(t_pipex *pipex, char *cmd, char *envp[], int i);
//error
void	exit_with_msg(char *err_msg);
//get_next_line
char	*get_next_line(int fd);

#endif
