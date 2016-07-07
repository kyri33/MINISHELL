/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 11:52:03 by khamusek          #+#    #+#             */
/*   Updated: 2016/05/14 11:52:04 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	src_pos;
	int	dest_pos;

	src_pos = 0;
	dest_pos = 0;
	while (dest[dest_pos] != '\0')
		dest_pos++;
	while (src[src_pos] != '\0')
	{
		dest[dest_pos] = src[src_pos];
		dest_pos++;
		src_pos++;
	}
	dest[dest_pos] = '\0';
	return (dest);
}
