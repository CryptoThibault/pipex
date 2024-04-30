/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:51:10 by tchalaou          #+#    #+#             */
/*   Updated: 2024/04/03 15:32:18 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_process(t_input *input, int pipes[2][2])
{
	close(input->fd_out);
	close(pipes[0][0]);
	close(pipes[1][0]);
	close(pipes[1][1]);
	dup2(input->fd_in, STDIN_FILENO);
	close(input->fd_in);
	dup2(pipes[0][1], STDOUT_FILENO);
	close(pipes[0][1]);
}

static void	last_process(t_input *input, int pipes[2][2], int even)
{
	close(input->fd_in);
	close(pipes[!even][1]);
	close(pipes[even][0]);
	close(pipes[even][1]);
	dup2(pipes[!even][0], STDIN_FILENO);
	close(pipes[!even][0]);
	dup2(input->fd_out, STDOUT_FILENO);
	close(input->fd_out);
}

void	child_process(char **args, t_input *input, int step, int pipes[2][2])
{
	int	even;

	even = step % 2;
	if (step == 0)
		first_process(input, pipes);
	else if (step == input->count - 1)
		last_process(input, pipes, even);
	else
	{
		close(input->fd_in);
		close(input->fd_out);
		close(pipes[!even][1]);
		close(pipes[even][0]);
		dup2(pipes[!even][0], STDIN_FILENO);
		close(pipes[!even][0]);
		dup2(pipes[even][1], STDOUT_FILENO);
		close(pipes[even][1]);
	}
	execve(args[0], args, NULL);
	perror_exit("command not executable", input);
}
