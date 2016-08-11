/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:23:25 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/11 13:13:37 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "defs.h"

static void		ft_run_command(char **cmd)
{
	if (ft_strnequ(*cmd, "exit", 5) == TRUE || ft_strnequ(*cmd, "exit ", 5))
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
	else if (ft_strnequ(*cmd, "./", 2) == TRUE || ft_strnequ(*cmd, "/", 1) ==
			TRUE)
		ft_execute(cmd);
	else if (ft_strnequ(*cmd, "", 1) == TRUE)
		return ;
	else
		ft_error(*cmd, "command not found");
}

void			ft_parse_command(char ***cmds)
{
	int		i;

	i = 0;
	while ((*cmds)[i] != NULL)
	{
		if (ft_rem_spaces(&((*cmds)[i])) == FALSE)
		{
			ft_error("An unexpected error occured while reading user input.",
				NULL);
			return ;
		}
		i++;
	}
	i = 0;
	while ((*cmds)[i] != NULL)
	{
		ft_run_command(&((*cmds)[i]));
		i++;
	}
}
