/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:13:56 by lagea             #+#    #+#             */
/*   Updated: 2024/06/14 14:25:34 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void child_process(int *fd, char **av, char **envp)
{
	int infile;
	char *err;
	
	close(fd[1]);
	infile = open(av[1], O_RDONLY, 0777);
	if (infile == -1)
	{
		err = strerror(errno);
		write(2, "zsh: ", 5);
		write(2, err, ft_strlen(err));
		write(2, ": ", 2);
		write(2, av[1], ft_strlen(av[1]));
		write(2, "\n", 1);
		exit(1);
	}
	
}

void parent_process(int *fd, char **av, char **envp)
{
	int outfile;
	char *err;

	close(fd[0]);
	outfile = open(av[4], O_WRONLY, 0777);
	if (outfile == -1)
	{
		err = strerror(errno);
		write(2, "zsh: ", 5);
		write(2, err, ft_strlen(err));
		write(2, ": ", 2);
		write(2, av[4], ft_strlen(av[4]));
		write(2 , "\n", 1);
		exit(1);
	}
}
