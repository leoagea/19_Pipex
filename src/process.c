/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:13:56 by lagea             #+#    #+#             */
/*   Updated: 2024/06/17 14:45:32 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static char	*path_cmd(char *cmd, char **envp, int i)
{
	char	**dir_cmd;
	char	*temp;
	char	*final_path;

	i = -1;
	while (ft_strncmp(envp[++i], "PATH", 4) != 0)
		;
	dir_cmd = ft_split(*(envp + i) + 5, ':');
	if (!dir_cmd)
		exit_malloc();
	i = -1;
	while (dir_cmd[++i])
	{
		temp = ft_strjoin("/", cmd);
		if (!temp)
			exit_malloc();
		final_path = ft_strjoin(dir_cmd[i], temp);
		if (!final_path)
			exit_malloc();
		free(temp);
		if (access(final_path, F_OK) == 0)
			return (free_arr(dir_cmd), final_path);
		free(final_path);
	}
	return (free_arr(dir_cmd), NULL);
}

static void	execution(char *cmd, char **envp)
{
	char	*path;
	char	**cmd_arr;

	cmd_arr = ft_split(cmd, ' ');
	if (!cmd_arr)
		exit_malloc();
	if (ft_strncmp(cmd_arr[0], "cd", 2) == 0)
	{
		free_arr(cmd_arr);
		exit(1);
	}
	if (access(cmd, F_OK) != 0)
		path = path_cmd(cmd_arr[0], envp, -1);
	else
		path = cmd;
	if (!path)
		wrong_path(cmd_arr);
	if (execve(path, cmd_arr, envp) == -1)
	{
		free(path);
		free_arr(cmd_arr);
		exit_error();
	}
	free(path);
	free_arr(cmd_arr);
}

void	child_process(int *fd, char **av, char **envp)
{
	int		infile;
	char	*err;

	close(fd[0]);
	infile = open(av[1], O_RDONLY, 0700);
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
	if (dup2(infile, STDIN_FILENO) == -1)
		exit_error();
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		exit_error();
	close(fd[1]);
	close(infile);
	execution(av[2], envp);
}

void	parent_process(int *fd, char **av, char **envp)
{
	int		outfile;
	char	*err;

	close(fd[1]);
	outfile = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0700);
	if (outfile == -1)
	{
		err = strerror(errno);
		write(2, "zsh: ", 5);
		write(2, err, ft_strlen(err));
		write(2, ": ", 2);
		write(2, av[4], ft_strlen(av[4]));
		write(2, "\n", 1);
		exit(1);
	}
	if (dup2(outfile, STDOUT_FILENO) == -1)
		exit_error();
	if (dup2(fd[0], STDIN_FILENO) == -1)
		exit_error();
	close(fd[0]);
	close(outfile);
	execution(av[3], envp);
}

static void	wrong_path(char **cmd)
{
	write(2, "zsh: command not found:", 23);
	write(2, cmd[0], ft_strlen(cmd[0]));
	write(2, "\n", 1);
	free_arr(cmd);
	exit(127);
}
