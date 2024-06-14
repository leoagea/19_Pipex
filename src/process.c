/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:13:56 by lagea             #+#    #+#             */
/*   Updated: 2024/06/14 18:05:25 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"


static char *path_cmd(char *cmd, char **envp)
{
	char **dir_cmd;
	char *temp;
	char *final_path;
	int i;

	i = -1;
	while (ft_strncmp(envp[++i], "PATH", 4) != 0);
	dir_cmd = ft_split(*(envp + i) + 5, ':');
	if (!dir_cmd)
	{
		write(2, "Error memory allocation\n", 24);
		exit(1);
	}
	i = -1;
	while(dir_cmd[++i])
	{
		temp = ft_strjoin("/", cmd);
		if (!temp)
		{
			write(2, "Error memory allocation\n", 24);
			exit(1);
		}
		final_path = ft_strjoin(dir_cmd[i], temp);
		if (!final_path)
		{
			write(2, "Error memory allocation\n", 24);
			exit(1);
		}
		free(temp);
		if (access(final_path, F_OK) == 0)
		{
			int j = -1;
			while (dir_cmd[++j])
				free(dir_cmd[j]);
			free(dir_cmd);
			return final_path;
		}		
		free(final_path);
	}
	int j = -1;
	while (dir_cmd[++j])
		free(dir_cmd[j]);
	free(dir_cmd);
	return NULL;
}

static void execution(char *cmd, char **envp)
{
	char *path;
	char **cmd_arr;
	
	cmd_arr = ft_split(cmd, ' ');
	if (!cmd_arr)
	{
		write(2, "Error memory allocation\n", 24);
		exit(1);
	}
	if (ft_strncmp(cmd_arr[0], "cd", 2) == 0)
		exit(1);
	if (access(cmd, F_OK) != 0)
		path = path_cmd(cmd_arr[0], envp);
	else
		path = cmd;
	if (!path)
	{
		write(2, "zsh: command not found:",23);
		write(2, cmd_arr[0], ft_strlen(cmd_arr[0]));
		write(2, "\n", 1);
		int i = -1;
		while(cmd_arr[++i])
			free(cmd_arr[i]);
		free(cmd_arr);
		exit(127);
	}
	if (execve(path, cmd_arr, envp) == -1)
	{
		free(path);
		int i = -1;
		while (cmd_arr[++i])
			free(cmd_arr[i]);
		free(cmd_arr);
		perror("zsh");
		exit(1);
	}
	free(path);
	int i = -1;
	while (cmd_arr[++i])
		free(cmd_arr[i]);
	free(cmd_arr);
}

void child_process(int *fd, char **av, char **envp)
{
	int infile;
	char *err;
	
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
	{
		perror("zsh");
		exit(1);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("zsh");
		exit(1);
	}
	close(fd[1]);
	close(infile);
	execution(av[2],envp);
}

void parent_process(int *fd, char **av, char **envp)
{
	int outfile;
	char *err;

	close(fd[1]);
	outfile = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0700);
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
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		perror("zsh");
		exit(1);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("zsh");
		exit(1);
	}
	close(fd[0]);
	close(outfile);
	execution(av[3],envp);
}
