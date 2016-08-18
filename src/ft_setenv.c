/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:25:16 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/18 17:09:03 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "defs.h"

static t_bool	ft_set_var(char *name, char *val, char ***env, int i)
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
	free((*env)[i]);
	free(tmp);
	(*env)[i] = tmp2;
	return (TRUE);
}

static t_bool	ft_dup_env(char ***environ, char ***tmp)
{
	int		size;
	int		i;

	size = 0;
	i = 0;
	while ((*environ)[size] != NULL)
		size++;
	if ((*tmp = (char **)malloc(sizeof(char *) * (size + 2))) == NULL)
		return (FALSE);
	while (i < size)
	{
		if (((*tmp)[i] = ft_strdup((*environ)[i])) == NULL)
			return (FALSE);
		i++;
	}
	(*tmp)[i] = NULL;
	(*tmp)[i + 1] = NULL;
	return (TRUE);
}

static t_bool	ft_add_var(char *name, char *val, char ***env)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = NULL;
	if (ft_dup_env(env, &tmp) == FALSE)
		return (FALSE);
	while (tmp[i] != NULL)
		i++;
	if (ft_set_var(name, val, &tmp, i) == FALSE)
		return (FALSE);
	*env = tmp;
	return (TRUE);
}

static t_bool	ft_set(char *str)
{
	extern char	**environ;
	char		*eq;
	int			i;

	i = 0;
	eq = NULL;
	while (environ[i] != NULL)
	{
		eq = ft_strchr(environ[i], '=');
		if (ft_strequ(ft_get_env_name(environ[i]), name) == TRUE)
		{
			if (ft_set_var(name, val, &environ, i) == FALSE)
				return (FALSE);
			else
				return (TRUE);
		}
		i++;
	}
	return (ft_add_var(name, val, &environ));
}

void			ft_setenv(char **cmd)
{
	int		i;
	char	**vars;

	i = 0;
	vars = NULL;
	if ((vars = ft_fill_args((*cmd) + 7, ' ')) == NULL)
		ft_error("Unable to set environment variable.", NULL);
	while (vars[i] != NULL)
	{
		if (ft_strchr(vars[i], '=') == NULL)
		{
			ft_error("Usage: setenv [NAME]=[VALUE]", NULL);
			break ;
		}
		i++;
	}
	i = 0;
	while (vars[i] != NULL)
	{
		if (ft_set(vars[i]) == FALSE)
		{
			ft_error("Unable to set environment variable", vars[i]);
			break ;
		}
		i++;
	}
	ft_del_args(&vars);
}
