/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 11:32:05 by khamusek          #+#    #+#             */
/*   Updated: 2016/05/14 11:32:16 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*b;

	i = 0;
	b = (unsigned char *)s;
	while (*b && i < n)
	{
		if (*b == (unsigned char)c)
			return ((void *)b);
		b++;
		i++;
	}
	if (!(unsigned char)c && *b == (unsigned char)c)
		return ((void *)b);
	return (NULL);
}
