/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 18:37:09 by kioulian          #+#    #+#             */
/*   Updated: 2016/10/25 18:20:48 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	PID = -1;

int		search_commands(t_env *e)
{
	if (ft_strcmp(e->args[0], "cd") == 0)
	{
		if (!e->args[1] || chdir(e->args[1]) != 0)
			ft_putstr("cd: directory not found\n");
	}
	else if (ft_strcmp(e->args[0], "echo") == 0)
		ft_echo(e);
	else if (ft_strcmp(e->args[0], "setenv") == 0)
		ft_setenv(e);
	else if (ft_strcmp(e->args[0], "unsetenv") == 0)
	{
		if (!ft_unsetenv(e))
			ft_putstr("Variable not found\n");
	}
	else if (ft_strcmp(e->args[0], "env") == 0)
		ft_env(e);
	else
		return (search_paths(e));
	return (0);
}

void	process_line(t_env *e)
{
	int	i;

	i = 0;
	e->commands = ft_strsplit(e->line, ';');
	while (e->commands[i])
	{
		e->args = ft_strsplit(e->commands[i], ' ');
		if (search_commands(e) > 0)
			run_command(e);
		i++;
	}
}

void	begin_shell(t_env *e)
{
	ft_putstr("$> ");
	get_next_line(0, &e->line);
	if (ft_strcmp(e->line, "exit") != 0)
	{
		if (ft_strcmp(e->line, "") != 0)
		{
			process_line(e);
			free(e->line);
			e->line = NULL;
			if (e->args)
				free_tab(e->args);
		}
		begin_shell(e);
	}
	else
	{
		free(e->line);
		e->line = NULL;
		free_tab(e->environ);
	}
}

int		main(void)
{
	t_env		e;
	
	signal(SIGINT, signal_c);
	get_environ(&e);
	begin_shell(&e);
	return (1);
}
