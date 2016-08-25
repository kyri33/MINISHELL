/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:23:25 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/22 17:00:23 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

static void		ft_fork_path(char ***argv)
{
	pid_t		pid;
	extern char	**environ;

	pid = -1;
	if ((pid = fork()) >= 0)
	{
		if (pid == 0)
		{
			if (execve((*argv)[0], (*argv), environ) < 0)
				ft_error("Unable to execute program", (*argv)[0]);
		}
		else
			waitpid(pid, NULL, 0);
	}
}

static t_bool	ft_run_path(char *cmd, char *path)
{
	t_bool	ret;
	char	**argv;
	char	*prog;

	argv = NULL;
	ret = FALSE;
	if ((prog = ft_strjoin_path(path, cmd)) == NULL)
		return (FALSE);
	if (ft_fill_args(prog, &argv) == FALSE)
	{
		free(prog);
		return (FALSE);
	}
	if (access(argv[0], F_OK) < 0)
		ret = FALSE;
	else
	{
		ft_fork_path(&argv);
		ret = TRUE;
	}
	free(prog);
	ft_del_args(&argv);
	return (ret);
}

static t_bool	ft_execute_path(char *cmd)
{
	int		i;
	char	*str;
	char	**path;
	t_bool	ret;

	i = 0;
	str = NULL;
	path = NULL;
	ret = FALSE;
	if ((str = ft_get_env("PATH")) == NULL)
		return (FALSE);
	if ((path = ft_strsplit(str, ':')) == NULL)
	{
		free(str);
		return (FALSE);
	}
	while (path[i] != NULL && ret == FALSE)
	{
		ret = ft_run_path(cmd, path[i]);
		i++;
	}
	free(str);
	ft_del_args(&path);
	return (ret);
}

void		ft_run_command(char **cmd)
{
	if (ft_strnequ(*cmd, "exit", 5) == TRUE || ft_strnequ(*cmd, "exit ", 5))
		ft_exit(cmd, EXIT_SUCCESS, NULL);
	else if (ft_strnequ(*cmd, "echo", 4) == TRUE ||
			ft_strnequ(*cmd, "echo ", 5))
		ft_echo(cmd);
	else if (ft_strnequ(*cmd, "cd", 3) == TRUE ||
			ft_strnequ(*cmd, "cd ", 3) == TRUE)
		ft_cd(cmd);
	else if (ft_strnequ(*cmd, "setenv", 6) == TRUE || ft_strnequ(*cmd,
				"setenv ", 7) == TRUE)
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
	else if (ft_execute_path(*cmd) == FALSE)
		ft_error(*cmd, "command not found");
}

void			ft_parse_command(char ***cmds)
{
	int		i;
	char	**pipes;

	i = 0;
	pipes = NULL;
	while ((*cmds)[i] != NULL)
	{
		if ((pipes = ft_strsplit((*cmds)[i], '|')) == NULL)
		{
			ft_error("An unexpected error occured while reading user input.",
				NULL);
			return ;
		}
		ft_exec_pipes(&pipes);
		ft_del_args(&pipes);
		pipes = NULL;
		i++;
	}
}
