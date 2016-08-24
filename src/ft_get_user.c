/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_user.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:26:17 by khamusek          #+#    #+#             */
/*   Updated: 2016/07/08 13:30:19 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

const char	*ft_get_user(void)
{
	int			i;
	extern char	**environ;
	char		*user;

	i = 0;
	while (environ[i] != NULL)
	{
		if (ft_strnequ(environ[i], "USER=", 5) == TRUE)
			break ;
		i++;
	}
	user = ft_strchr(environ[i], '=');
	if (user == NULL)
		return (NULL);
	return (user + 1);
}
