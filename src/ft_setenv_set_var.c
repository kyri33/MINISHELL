/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv_set_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 16:23:01 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/22 17:12:20 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

static t_bool	ft_set_var(char *name, char *val, char **env)
{
	char	*tmp;
	char	*tmp2;
	char	*var;

	tmp = NULL;
	tmp2 = NULL;
	var = NULL;
	if ((tmp = ft_strjoin(name, "=")) == NULL)
		return (FALSE);
	if ((tmp2 = ft_strjoin(tmp, val)) == NULL)
	{
		free(tmp);
		return (FALSE);
	}
	free(*env);
	free(tmp);
	(*env) = tmp2;
	return (TRUE);
}

int				ft_setenv_set_var(char *name, char *val, char **env)
{
	char	*tmp;

	if ((tmp = ft_get_env_name(*env)) == NULL)
		return (-1);
	if (ft_strequ(name, tmp) == TRUE)
	{
		if (ft_set_var(name, val, env) == FALSE)
		{
			free(tmp);
			return (-1);
		}
		else
		{
			free(tmp);
			return (1);
		}
	}
	free(tmp);
	return (0);
}
