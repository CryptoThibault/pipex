/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:13:05 by tchalaou          #+#    #+#             */
/*   Updated: 2024/04/03 15:34:21 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_input *input)
{
	int	pipes[2][2];
	int	step;

	if (pipe(pipes[0]) == -1 || pipe(pipes[1]) == -1)
		perror_exit("pipe creation failed", input);
	step = -1;
	while (++step < input->count)
	{
		if (step > 1)
		{
			close(pipes[step % 2][0]);
			close(pipes[step % 2][1]);
			if (pipe(pipes[step % 2]) == -1)
				perror_exit("pipe creation failed", input);
		}
		exec_cmd(input, step, pipes);
	}
	while (--step > 0)
		wait(NULL);
	close(pipes[0][0]);
	close(pipes[0][1]);
	close(pipes[1][0]);
	close(pipes[1][1]);
}
