/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjoon <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:51:02 by seungjoon         #+#    #+#             */
/*   Updated: 2022/07/06 20:51:05 by seungjoon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exit_with_msg(char *err_msg)
{
	unlink(".heredoc_tmp");
	write(2, err_msg, ft_strlen(err_msg));
	exit(1);
}
