/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:02:20 by lagea             #+#    #+#             */
/*   Updated: 2024/06/17 13:37:18 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	check_perm(char **av)
{
	if (ft_strncmp(av[2], "/dev/stdin", 10) == 0 || ft_strncmp(av[2],
			"/dev/random", 11) == 0 || ft_strncmp(av[2], "/dev/urandom",
			12) == 0)
	{
		write(2, "zsh: permission denied :", 24);
		write(2, av[2], ft_strlen(av[2]));
		write(2, "\n", 1);
		exit(1);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	id;

	if (ac < 5)
	{
		write(2, "Not enough arguments\n", 21);
		return (1);
	}
	if (ac > 5)
	{
		write(2, "Too much arguments\n", 19);
		return (1);
	}
	if (!envp || !*envp)
		return 1;
	check_perm(av);
	if (pipe(fd) == -1)
		exit_error();
	id = fork();
	if (id == -1)
		exit_error();
	if (id != 0)
	{
		id = fork();
		if (id == -1)
			exit_error();
		if (id == 0)
			parent_process(fd, av, envp);	
		wait(NULL);
	}
	if (id == 0)
		child_process(fd, av, envp);
	wait(NULL);
	return (0);
}
