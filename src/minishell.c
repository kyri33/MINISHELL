/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:23:17 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/04 14:24:13 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "defs.h"

/*static t_bool	ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

static int		ft_length(char *cmd)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (cmd[i] != '\0' && ft_isspace(cmd[i]) == TRUE)
		i++;
	while (cmd[i] != '\0')
	{
		if (ft_isspace(cmd[i]) == TRUE && ft_isspace(cmd[i + 1]) == FALSE &&
				cmd[i + 1] != '\0')
				count++;
		else if (ft_isspace(cmd[i]) == FALSE)
			count++;
		i++;
	}
	return (count);
}

static void		ft_rem_tabs(char **cmd)
{
	int		i;

	i = 0;
	while ((*cmd)[i] != '\0')
	{
		if ((*cmd)[i] == '\t')
			(*cmd)[i] = ' ';
		i++;
	}
}

static t_bool	ft_rem_spaces(char **cmd)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if ((ret = (char *)malloc(sizeof(char) * (ft_length(*cmd) + 1))) == NULL)
		return (FALSE);
	ft_rem_tabs(cmd);
	while ((*cmd)[i] != '\0' && ft_isspace((*cmd)[i]) == TRUE)
		i++;
	while ((*cmd)[i] != '\0')
	{
		if ((ft_isspace((*cmd)[i]) == TRUE && ft_isspace((*cmd)[i + 1]) == FALSE
				&& (*cmd)[i + 1] != '\0') || ft_isspace((*cmd)[i]) == FALSE)
		{
			ret[j] = (*cmd)[i];
			j++;
		}
		i++;
	}
	ret[j] = '\0';
	free((*cmd));
	(*cmd) = ret;
	return (TRUE);
}*/

static void		ft_free_data(char **cmd, char ***cmds)
{
	if ((*cmd) != NULL)
		free (*cmd);
	ft_del_args(cmds);
	(*cmd) = NULL;
	(*cmds) = NULL;
}

int				main(void)
{
	char		*cmd;
	char		**cmds;

	cmd = NULL;
	cmds = NULL;
	while (1)
	{
		ft_free_data(&cmd, &cmds);
		ft_printf("%s%s%s@%s21sh$%s ", CCYN, ft_get_user(), CNRM, CMAG,
				CNRM);
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
	ft_exit(&cmd, EXIT_SUCCESS, NULL);
	return (0);
}
