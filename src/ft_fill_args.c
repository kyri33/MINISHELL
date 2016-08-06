/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:24:44 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/04 13:46:22 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "defs.h"

static char		*ft_var(char *str)
{
	int			size;
	char		*ret;
	int			i;
	extern char	**environ;

	size = 0;
	i = 0;
	ret = NULL;
	while (str[size] != '\0')
		size++;
	size--;
	while (environ[i] != NULL)
	{
		if (ft_strnequ(environ[i], str + 1, size) == TRUE)
		{
			ret = ft_get_env_val(ft_strchr(environ[i], '='));
			return (ret);
		}
		i++;
	}
	return (NULL);
}

static t_bool	ft_parse_env(char ***argv)
{
	int			i;
	char		*val;
	extern char	**environ;

	i = 0;
	while ((*argv)[i] != NULL)
	{
		if (ft_strnequ((*argv)[i], "$", 1) == TRUE)
		{
			if ((val = ft_var((*argv)[i])) == NULL)
				val = ft_strdup("");
			if (val == NULL)
				return (FALSE);
			free ((*argv)[i]);
			(*argv)[i] = val;
			return (TRUE);
		}
		i++;
	}
	return (TRUE);
}

t_bool			ft_fill_args(char **cmd, char ***argv)
{
	if (((*argv) = ft_strsplit(*cmd, ' ')) == NULL)
		return (FALSE);
	if (ft_parse_env(argv) == FALSE)
		return (FALSE);
	return (TRUE);
}
