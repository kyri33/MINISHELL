/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:23:25 by khamusek          #+#    #+#             */
/*   Updated: 2016/07/08 15:03:32 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "defs.h"

void	ft_parse_command(char **cmd)
{
	if (ft_strnequ(*cmd, "exit", 5) == TRUE ||
			ft_strnequ(*cmd, "exit ", 5))
		ft_exit(cmd, EXIT_SUCCESS, NULL);
	else if (ft_strnequ(*cmd, "echo", 4) == TRUE ||
			ft_strnequ(*cmd, "echo ", 5))
		ft_echo(cmd);
	else if (ft_strnequ(*cmd, "cd", 3) == TRUE ||
			ft_strnequ(*cmd, "cd ", 3) == TRUE)
		ft_cd(cmd);
	else if (ft_strnequ(*cmd, "setenv", 6) == TRUE)
		ft_setenv(cmd);
	else if (ft_strnequ(*cmd, "env", 4) == TRUE || ft_strnequ(*cmd,
			"env ", 5) == TRUE)
		ft_env();
	else if (ft_strnequ(*cmd, "pwd ", 4) == TRUE || ft_strnequ(*cmd,
			"pwd", 4) == TRUE)
		ft_pwd();
	else if (ft_strnequ(*cmd, "unsetenv", 6) == TRUE)
		ft_unsetenv(cmd);
	else if (ft_strnequ(*cmd, "./", 2) == TRUE)
		ft_execute(cmd);
	else
		ft_error(*cmd, "command not found");
}
