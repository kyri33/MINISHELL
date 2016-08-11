/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 14:14:45 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/11 14:47:05 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "defs.h"

static char	*ft_get_env_val(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (NULL);
	i++;
	ret = ft_strdup(str + i);
	return (ret);
}

static t_bool	ft_isenv_var(char *s1, char *s2)
{
}

char		*ft_get_env(char *var)
{
	int			i;
	extern char	**environ;

	i = 0;
	while (environ[i] != NULL)
	{
		if (ft_isenv_var(var, environ[i]) == TRUE)
			return (ft_get_env_val(environ[i]));
		i++;
	}
	return (NULL);
}
