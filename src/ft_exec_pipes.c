/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 13:20:04 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/26 13:44:36 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

static void	ft_run_pipe(char ***pipes, int i, int pipefd[2], int std_cpy[2])
{
	if (i == 0 && (*pipes)[i + 1] != NULL)
	{
		dup2(pipefd[1], 1);
		ft_run_command(&((*pipes)[i]));
		dup2(pipefd[0], 0);
	}
	else if (i > 0 && (*pipes)[i + 1] == NULL)
	{
		close(pipefd[1]);
		dup2(std_cpy[1], 1);
		ft_run_command(&((*pipes)[i]));
		dup2(std_cpy[0], 0);
	}
	else
		ft_run_command(&((*pipes)[i]));
}

static void	ft_run_pipes(char ***pipes)
{
	int		i;
	int		pipefd[2];
	int		std_cpy[2];

	i = 0;
	std_cpy[0] = dup(0);
	std_cpy[1] = dup(1);
	if (pipe(pipefd) != 0)
	{
		ft_error("Unable to initialise I/O pipes.", NULL);
		return ;
	}
	while ((*pipes)[i] != NULL)
	{
		ft_run_pipe(pipes, i, pipefd, std_cpy);
		i++;
	}
	close(pipefd[0]);
	close(pipefd[1]);
	close(std_cpy[0]);
	close(std_cpy[1]);
}

void		ft_exec_pipes(char ***pipes)
{
	int		i;

	i = 0;
	while ((*pipes)[i] != NULL)
	{
		if (ft_rem_spaces(&((*pipes)[i])) == FALSE)
		{
			ft_error("An unexpected error occured while parsing user input.",
				NULL);
			return ;
		}
		i++;
	}
	ft_run_pipes(pipes);
}
