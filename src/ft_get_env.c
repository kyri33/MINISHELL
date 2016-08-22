/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 14:14:45 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/22 16:46:04 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "defs.h"

static char		*ft_get_val(char *str)
{
	char	*eq;

	eq = NULL;
	if ((eq = ft_strchr(str, '=')) == NULL)
		return (NULL);
	return (ft_strdup(eq + 1));
}

static t_bool	ft_isenv_var(char *name, char *env_var)
{
	int		i;

	i = 0;
	if (ft_strchr(name, '=') != NULL || ft_strchr(env_var, '=') == NULL)
		return (FALSE);
	while (name[i] != '\0' && env_var[i] != '\0' && env_var[i] != '=')
	{
		if (name[i] != env_var[i])
			return (FALSE);
		i++;
	}
	if (name[i] == '\0' && env_var[i] == '=')
		return (TRUE);
	else
		return (FALSE);
}

char			*ft_get_env(char *var)
{
	int			i;
	extern char	**environ;

	i = 0;
	while (environ[i] != NULL)
	{
		if (ft_isenv_var(var, environ[i]) == TRUE)
			return (ft_get_val(environ[i]));
		i++;
	}
	return (NULL);
}
