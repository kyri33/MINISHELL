/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:25:16 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/22 17:08:42 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "defs.h"

static t_bool	ft_set_var(char *name, char *val, char **env)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = NULL;
	if ((tmp = ft_strjoin(name, "=")) == NULL)
		return (FALSE);
	if ((tmp2 = ft_strjoin(tmp, val)) == NULL)
	{
		free(tmp);
		return (FALSE);
	}
	free(tmp);
	(*env) = tmp2;
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
	if (ft_set_var(name, val, &(tmp[i])) == FALSE)
		return (FALSE);
	*env = tmp;
	return (TRUE);
}

static t_bool	ft_set(char *str)
{
	int			i;
	int			ret;
	char		*name;
	char		**tmp;
	extern char	**environ;

	i = 0;
	ret = 0;
	name = NULL;
	if ((tmp = ft_strsplit(str, '=')) == NULL)
		return (FALSE);
	while (environ[i] != NULL)
	{
		ret = ft_setenv_set_var(tmp[0], tmp[1], &(environ[i]));
		if (ret == -1 || ret == 1)
		{
			ft_del_args(&tmp);
			return (ret == 1);
		}
		i++;
	}
	ret = (int)ft_add_var(tmp[0], tmp[1], &environ);
	ft_del_args(&tmp);
	return ((t_bool)ret);
}

void			ft_setenv(char **cmd)
{
	int		i;
	char	**vars;

	i = 0;
	vars = NULL;
	if ((vars = ft_strsplit((*cmd) + 7, ' ')) == NULL)
		ft_error("Unable to set environment variable.", NULL);
	else if (ft_setenv_check_vars(&vars) == TRUE)
	{
		while (vars[i] != NULL)
		{
			if (ft_set(vars[i]) == FALSE)
			{
				ft_error("Unable to set environment variable", vars[i]);
				break ;
			}
			i++;
		}
	}
	ft_del_args(&vars);
}
