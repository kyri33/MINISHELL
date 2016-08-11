/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rem_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 13:14:21 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/11 13:14:24 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "defs.h"

static t_bool	ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

static int		ft_length(char *cmd)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (cmd[i] != '\0' && ft_isspace(cmd[i]) == TRUE)
		i++;
	while (cmd[i] != '\0')
	{
		if (ft_isspace(cmd[i]) == TRUE && ft_isspace(cmd[i + 1]) == FALSE &&
				cmd[i + 1] != '\0')
			size++;
		else if (ft_isspace(cmd[i]) == FALSE)
			size++;
		i++;
	}
	return (size);
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

t_bool			ft_rem_spaces(char **cmd)
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
	free(*cmd);
	(*cmd) = ret;
	return (TRUE);
}
