/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:14:15 by tchalaou          #+#    #+#             */
/*   Updated: 2024/04/19 15:57:21 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **ep)
{
	t_input	*input;
	int		here_doc;

	here_doc = 0;
	if (ac > 4 && !ft_strncmp(av[1], "here_doc", 8))
	{
		ac--;
		av++;
		here_doc = 1;
	}
	if (ac < 5)
		perror_exit("not enough arguments", NULL);
	input = fill_input(ac - 1, av + 1, ep);
	open_files(input, here_doc);
	pipex(input);
	close(input->fd_in);
	close(input->fd_out);
	free_array(input->path);
	free(input);
	return (0);
}
