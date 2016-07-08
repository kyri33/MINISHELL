/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:24:19 by khamusek          #+#    #+#             */
/*   Updated: 2016/07/08 13:28:16 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "libft.h"
#include "defs.h"

void	ft_echo(char **cmd)
{
	extern char	**environ;
	char		**argv;
	pid_t		pid;

	argv = NULL;
	pid = -1;
	if (ft_fill_args(cmd, &argv) == TRUE)
	{
		if ((pid = fork()) >= 0)
		{
			if (pid == 0)
				execve("/bin/echo", argv, environ);
			else
				waitpid(pid, 0, 0);
		}
		else
			ft_error("Cannot execute command. Process\
					initialisation failed.", NULL);
	}
	else
		ft_error("There was an unexpected error executing the\
				command", "echo");
	ft_del_args(&argv);
}
