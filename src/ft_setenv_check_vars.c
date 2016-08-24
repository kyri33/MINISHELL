/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv_check_vars.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:53:32 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/22 17:10:31 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

t_bool	ft_setenv_check_vars(char ***vars)
{
	int		i;

	i = 0;
	while ((*vars)[i] != NULL)
	{
		if (ft_strchr((*vars)[i], '=') == NULL)
		{
			ft_error("Usage: setenv [NAME]=[VALUE]", NULL);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
