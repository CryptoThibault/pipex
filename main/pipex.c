/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:13:05 by tchalaou          #+#    #+#             */
/*   Updated: 2024/04/04 12:52:44 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_input *input)
{
	int	pi[2];

	if (pipe(pi) == -1)
		perror_exit("pipe creation failed", input);
	exec_cmd(input, 0, pi);
	exec_cmd(input, 1, pi);
	wait(NULL);
	close(pi[0]);
	close(pi[1]);
}
