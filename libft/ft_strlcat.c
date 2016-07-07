/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 11:46:21 by khamusek          #+#    #+#             */
/*   Updated: 2016/05/14 11:46:22 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	res_len;
	size_t	diff;

	res_len = 0;
	while (res_len < size && dest[0] && *(dest++))
		res_len++;
	diff = size - res_len;
	if (diff <= 0)
		return (res_len + ft_strlen(src));
	while (src[0])
	{
		if (diff > 1)
		{
			*(dest++) = *src;
			diff--;
		}
		src++;
		res_len++;
	}
	dest[0] = '\0';
	return (res_len);
}
