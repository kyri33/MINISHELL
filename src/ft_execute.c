/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:03:45 by khamusek          #+#    #+#             */
/*   Updated: 2016/07/08 15:17:18 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "libft.h"
#include "defs.h"

void	ft_execute(char **cmd)
{
	pid_t		pid;
	char		**argv;
	extern char	**environ;

	pid = -1;
	if (ft_fill_args(cmd, &argv) == FALSE)
		ft_error("Unable to parse command arguments.", NULL);
	else
	{
		if (access(argv[0], F_OK) < 0)
			ft_error("No such file or directory exists", argv[0]);
		else if ((pid = fork()) >= 0)
		{
			if (pid == 0)
			{
				if (execve(argv[0], argv, environ) < 0)
					ft_error("Unable to execute program", argv[0]);
			}
			else
				waitpid(pid, 0, 0);
		}
		else
			ft_error("Unable to execute program", argv[0]);
	}
	ft_del_args(&argv);
}
