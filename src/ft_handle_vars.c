/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 15:26:41 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/17 15:33:55 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "defs.h"

t_bool	ft_handle_vars(char **arg)
{
	char	*ret;
	char	*tmp;
	char	*mod;

	ret = NULL;
	tmp = NULL;
	mod = ft_strchr(*arg, '$');
	while (mod != NULL)
	{
		mod = ft_strchr(mod + 1, '$');
	}
	return (TRUE);
}
