/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:03:45 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/22 17:37:44 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

static void	ft_execve(char *prog, char ***args)
{
	extern char	**environ;

	if (execve(prog, *args, environ) < 0)
	{
		ft_error("Unable to execute program", prog);
		ft_del_args(args);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void		ft_execute(char **cmd)
{
	pid_t		pid;
	char		**argv;

	pid = -1;
	if (ft_fill_args(*cmd, &argv) == FALSE)
		ft_error("Unable to parse command arguments.", NULL);
	else
	{
		if (access(argv[0], X_OK) < 0)
			ft_error("Permission denied", argv[0]);
		else if ((pid = fork()) >= 0)
		{
			if (pid == 0)
			{
				ft_execve(argv[0], &argv);
			}
			else
				waitpid(pid, 0, 0);
		}
		else
			ft_error("Unable to execute program", argv[0]);
	}
	ft_del_args(&argv);
}
