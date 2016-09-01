/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:23:17 by khamusek          #+#    #+#             */
/*   Updated: 2016/09/01 15:43:54 by dnematan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "twentyonesh.h"

static void		ft_free_data(char **cmd, char ***cmds)
{
	if ((*cmd) != NULL)
		free(*cmd);
	ft_del_args(cmds);
	(*cmd) = NULL;
	(*cmds) = NULL;
}

static void		ft_loop(t_to *to)
{
	char	*cmd;
	char	**cmds;

	cmd = NULL;
	cmds = NULL;
	while (1)
	{
		ft_free_data(&cmd, &cmds);
		ft_printf("%s%s%s@%s21sh$%s ", CCYN, ft_get_user(), CNRM, CMAG, CNRM);
		ft_getline(&cmd, to);
		if (ft_rem_spaces(&cmd) == FALSE)
			ft_error("An unexpected error occured while reading user input.",
				NULL);
		if ((cmds = ft_strsplit(cmd, ';')) == NULL)
			ft_error("An unexpected error occured while parsing the command.",
				NULL);
		ft_parse_command(&cmds);
	}
	ft_free_data(&cmd, &cmds);
	reset_term(to);
	ft_exit(&cmd, EXIT_SUCCESS, NULL);
}

int				main(void)
{
	t_to			to;

	init_term(&to);
	ft_loop(&to);
	return (0);
}
