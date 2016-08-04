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

static t_bool	ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

static t_bool	ft_check_quotes(char *cmd)
{
	int		i;
	int		dbl_quote;
	int		sngl_quote;

	i = 0;
	dbl_quote = 0;
	sngl_quote = 0;
	while (cmd[i] != 0)
	{
		if (cmd[i] == '\'')
			sngl_quote = !sngl_quote;
		if (cmd[i] == '"')
			dbl_quote = !dbl_quote;
		i++;
	}
	if (dbl_quote != 0 || sngl_quote != 0)
		return (FALSE);
	return (TRUE);
}

static int		ft_length(char *cmd)
{
	int		count;
	int		i;
	int		sngl_quote;
	int		dbl_quote;

	count = 0;
	i = 0;
	sngl_quote = 0;
	dbl_quote = 0;
	while (cmd[i] != '\0' && ft_isspace(cmd[i]) == TRUE)
		i++;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '"')
			dbl_quote = !dbl_quote;
		else if (cmd[i] == '\'')
			sngl_quote = !sngl_quote;
		else if ((ft_isspace(cmd[i]) == TRUE && (sngl_quote != 0 || dbl_quote !=
					0) && ft_isspace(cmd[i + 1]) == FALSE && cmd[i + 1] != '\0')
					|| ft_isspace(cmd[i]) == FALSE)
			count++;
		i++;
	}
	return (count);
}

static t_bool	ft_rem_spaces(char **cmd)
{
	if (ft_check_quotes(*cmd) == FALSE)
		return (FALSE);
}

int				main(void)
{
	char		*cmd;

	cmd = NULL;
	while (1)
	{
		if (cmd != NULL)
		{
			free(cmd);
			cmd = NULL;
		}
		ft_printf("%s%s%s@%sminishell$%s ", CCYN, ft_get_user(), CNRM, CMAG,
				CNRM);
		if (get_next_line(STDIN, &cmd) == -1)
			ft_error("An unexpected error occured while\
				reading user input.", NULL);
		if (ft_rem_spaces(&cmd) == FALSE)
			ft_error("An unexpected error occured while\
				reading user input.", NULL);
		ft_parse_command(&cmd);
	}
	ft_exit(&cmd, EXIT_SUCCESS, NULL);
	return (0);
}
