/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:25:46 by khamusek          #+#    #+#             */
/*   Updated: 2016/07/08 13:25:47 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "defs.h"

void	ft_env(void)
{
	int			i;
	extern char	**environ;

	i = 0;
	while (environ[i] != NULL)
	{
		ft_putendl(environ[i]);
		i++;
	}
}
