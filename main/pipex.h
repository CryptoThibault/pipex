/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:08:55 by tchalaou          #+#    #+#             */
/*   Updated: 2024/04/03 15:47:21 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_input
{
	char	*infile;
	char	*outfile;
	int		fd_in;
	int		fd_out;
	int		count;
	char	**cmds;
	char	**path;
}		t_input;

void	free_array(char **array);
void	perror_exit(char *msg, t_input *input);
t_input	*fill_input(int count, char **value, char **ep);
void	open_files(t_input *input);
void	pipex(t_input *input);
void	exec_cmd(t_input *input, int step, int pi[2]);
void	child_process(char **args, t_input *input, int step, int pi[2]);
char	**get_path(char **ep);
char	*get_cmd_path(char *cmd_name, char **path);
#endif
