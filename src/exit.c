/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:45:14 by lagea             #+#    #+#             */
/*   Updated: 2024/06/17 14:48:12 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	exit_malloc(void)
{
	write(2, "Error memory allocation\n", 24);
	exit(1);
}

void	exit_error(void)
{
	perror("zsh");
	exit(1);
}

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}
