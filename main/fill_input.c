/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:22:25 by tchalaou          #+#    #+#             */
/*   Updated: 2024/04/15 12:52:44 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_input	*fill_input(int count, char **value, char **ep)
{
	t_input	*input;

	input = malloc(sizeof(t_input));
	if (!input)
		perror_exit("failing while malloc input struct", NULL);
	input->infile = value[0];
	input->outfile = value[count - 1];
	input->count = count - 2;
	input->cmds = value + 1;
	input->cmds[count - 2] = NULL;
	input->path = get_path(ep);
	if (!input->path)
	{
		free(input);
		perror_exit("path not found", NULL);
	}
	input->fd_in = -1;
	input->fd_out = -1;
	return (input);
}
