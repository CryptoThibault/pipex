/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:51:10 by tchalaou          #+#    #+#             */
/*   Updated: 2024/04/04 12:45:56 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **args, t_input *input, int step, int pi[2])
{
	if (!step)
	{
		close(input->fd_out);
		close(pi[0]);
		dup2(input->fd_in, STDIN_FILENO);
		close(input->fd_in);
		dup2(pi[1], STDOUT_FILENO);
		close(pi[1]);
	}
	else
	{
		close(input->fd_in);
		close(pi[1]);
		dup2(pi[0], STDIN_FILENO);
		close(pi[0]);
		dup2(input->fd_out, STDOUT_FILENO);
		close(input->fd_out);
	}
	execve(args[0], args, NULL);
	perror_exit("command not executable", input);
}
