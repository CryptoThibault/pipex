/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:35:08 by tchalaou          #+#    #+#             */
/*   Updated: 2024/04/19 15:47:40 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	write_tempfile(t_input *input)
{
	int		fd;
	char	*line;

	fd = open("/tmp/tempfile", O_RDWR | O_CREAT, 0644);
	while (1)
	{
		ft_putstr_fd("here_doc> ", 1);
		line = get_next_line(1);
		if (!ft_strncmp(line, input->infile, ft_strlen(input->infile)))
		{	
			free(line);
			break ;
		}
		if (!line)
			break ;
		ft_putstr_fd(line, fd);
		free(line);
	}
	close(fd);
	fd = open("/tmp/tempfile", O_RDONLY);
	unlink("/tmp/tempfile");
	return (fd);
}

void	open_files(t_input *input, int here_doc)
{
	if (!here_doc)
		input->fd_in = open(input->infile, O_RDONLY);
	else
		input->fd_in = write_tempfile(input);
	if (input->fd_in == -1)
		perror_exit("cannot open infile", input);
	if (!here_doc)
		input->fd_out = open(input->outfile, O_WRONLY
				| O_CREAT | O_TRUNC, 0644);
	else
		input->fd_out = open(input->outfile, O_WRONLY | O_CREAT, 0644);
	if (input->fd_out == -1)
		perror_exit("cannot open outfile", input);
}
