/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_val.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:25:00 by khamusek          #+#    #+#             */
/*   Updated: 2016/07/08 13:25:01 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

char	*ft_get_env_val(char *eq)
{
	int		i;
	int		size;
	char	*val;

	i = 0;
	size = 0;
	val = NULL;
	eq++;
	while (eq[size] != ' ' && eq[size] != '\t' && eq[size] != '\0')
		size++;
	if (size == 0)
		return (NULL);
	if ((val = ft_strnew(size)) != NULL)
	{
		while (i < size)
		{
			val[i] = eq[i];
			i++;
		}
		val[i] = '\0';
	}
	return (val);
}
