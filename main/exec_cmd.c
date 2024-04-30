/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:13:24 by tchalaou          #+#    #+#             */
/*   Updated: 2024/04/15 09:44:59 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(t_input *input, int step, int pi[2])
{
	char	**args;
	char	*temp;
	pid_t	pid;

	args = ft_split(input->cmds[step], ' ');
	temp = get_cmd_path(args[0], input->path);
	if (!temp)
	{
		free_array(args);
		free(temp);
		perror_exit("command not find", input);
	}
	free(args[0]);
	args[0] = temp;
	pid = fork();
	if (pid == -1)
		perror_exit("error while create a fork", input);
	if (!pid)
		child_process(args, input, step, pi);
	free_array(args);
}
