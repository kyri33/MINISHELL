/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:23:17 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/11 13:18:17 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

static void		ft_free_data(char **cmd, char ***cmds)
{
	if ((*cmd) != NULL)
		free(*cmd);
	ft_del_args(cmds);
	(*cmd) = NULL;
	(*cmds) = NULL;
}

static void		ft_loop(void)
{
	char	*cmd;
	char	**cmds;

	cmd = NULL;
	cmds = NULL;
	while (1)
	{
		ft_free_data(&cmd, &cmds);
		ft_printf("%s%s%s@%s21sh$%s ", CCYN, ft_get_user(), CNRM, CMAG, CNRM);
		if (get_next_line(STDIN, &cmd) == -1)
			ft_error("An unexpected error occured while reading user input.",
				NULL); 
		if (ft_rem_spaces(&cmd) == FALSE)
			ft_error("An unexpected error occured while reading user input.",
				NULL);
		if ((cmds = ft_strsplit(cmd, ';')) == NULL)
			ft_error("An unexpected error occured while parsing the command.",
				NULL);
		ft_parse_command(&cmds);
	}
	ft_free_data(&cmd, &cmds);
	ft_exit(&cmd, EXIT_SUCCESS, NULL);
}

int				main(void)
{
	char			*term_name;
	struct termios	term;

	term_name = NULL;
	if (ft_term_init(&term_name, &term) == FALSE)
	{
		ft_error("Could not initialise terminal.", NULL);
		return (-1);
	}
	ft_loop();
	return (0);
}
