/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:35:08 by tchalaou          #+#    #+#             */
/*   Updated: 2024/04/03 15:36:32 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(t_input *input)
{
	input->fd_in = open(input->infile, O_RDONLY);
	if (input->fd_in == -1)
		perror_exit("cannot open infile", input);
	input->fd_out = open(input->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (input->fd_out == -1)
		perror_exit("cannot open outfile", input);
}
