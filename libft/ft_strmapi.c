/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 11:45:52 by khamusek          #+#    #+#             */
/*   Updated: 2016/05/14 11:45:54 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			dest[i] = f((unsigned int)i, s[i]);
			i++;
		}
		return (dest);
	}
	else
		return (NULL);
}
