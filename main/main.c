/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:14:15 by tchalaou          #+#    #+#             */
/*   Updated: 2024/04/03 15:36:22 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **ep)
{
	t_input	*input;

	if (ac < 5)
		perror_exit("not enough arguments", NULL);
	if (ac > 5)
		perror_exit("too much arguments", NULL);
	input = fill_input(ac - 1, av + 1, ep);
	open_files(input);
	pipex(input);
	close(input->fd_in);
	close(input->fd_out);
	free_array(input->path);
	free(input);
	return (0);
}
