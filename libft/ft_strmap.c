/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 11:46:10 by khamusek          #+#    #+#             */
/*   Updated: 2016/05/14 11:46:11 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	int		i;

	i = 0;
	if (s && f)
	{
		dest = ft_strdup(s);
		if (!dest)
			return (NULL);
		while (dest[i] != '\0')
		{
			dest[i] = f(s[i]);
			i++;
		}
		return (dest);
	}
	else
		return (NULL);
}
