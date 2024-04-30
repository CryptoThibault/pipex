/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:11:41 by tchalaou          #+#    #+#             */
/*   Updated: 2024/04/15 09:18:30 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_exit(char *msg, t_input *input)
{
	if (input)
	{
		if (input->fd_in != -1)
			close(input->fd_in);
		if (input->fd_out != -1)
			close(input->fd_out);
		free_array(input->path);
		free(input);
	}
	perror(msg);
	exit(EXIT_FAILURE);
}
