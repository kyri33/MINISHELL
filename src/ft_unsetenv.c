/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:45:29 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/22 17:09:47 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

static int		ft_find_var(char *name)
{
	extern char	**environ;
	int			i;

	i = 0;
	while (environ[i] != NULL)
	{
		if (ft_strequ(name, ft_get_env_name(environ[i])) == TRUE)
			return (i);
		i++;
	}
	return (-1);
}

static t_bool	ft_del_index(char ***env, int index)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	while ((*env)[i] != NULL)
		i++;
	if ((tmp = (char **)malloc(sizeof(char *) * (i - 1))) == NULL)
		return (FALSE);
	i = 0;
	while ((*env)[i] != NULL)
	{
		if (index != i)
		{
			if ((tmp[j] = ft_strdup((*env)[i])) == NULL)
				return (FALSE);
			j++;
		}
		i++;
	}
	tmp[j] = NULL;
	*env = tmp;
	return (TRUE);
}

static t_bool	ft_rem_var(char *name)
{
	int			index;
	extern char	**environ;

	if ((index = ft_find_var(name)) == -1)
		return (TRUE);
	return (ft_del_index(&environ, index));
}

void			ft_unsetenv(char **cmd)
{
	int		i;
	char	**argv;

	argv = NULL;
	i = 1;
	if (ft_fill_args(*cmd, &argv) == FALSE)
		ft_error("Unable to parse arguments.", NULL);
	else if (ft_strnequ(*cmd, "unsetenv ", 7) == FALSE || argv[1] == NULL)
		ft_error("Usage: unsetenv [NAME]", NULL);
	else
	{
		while (argv[i] != NULL)
		{
			if (ft_rem_var(argv[i]) == FALSE)
			{
				ft_error("Unable to unset environment variable", argv[i]);
				break ;
			}
			i++;
		}
	}
	ft_del_args(&argv);
}
