/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:04:03 by lagea             #+#    #+#             */
/*   Updated: 2024/06/18 13:05:35 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

/*======================SRC=====================*/
/*--------------------process-------------------*/

void	child_process(int *fd, char **av, char **envp);
void	parent_process(int *fd, char **av, char **envp);

/*---------------------exit---------------------*/

void	exit_malloc(void);
void	exit_error(void);
void	ft_free(char **str);
void	free_arr(char **arr);

#endif