/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 11:35:14 by khamusek          #+#    #+#             */
/*   Updated: 2016/05/14 14:10:10 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	hay;
	int	ndl;

	hay = 0;
	if (needle[hay] == '\0')
		return ((char *)haystack);
	while (haystack[hay] != '\0')
	{
		ndl = 0;
		while (haystack[hay + ndl] == needle[ndl])
		{
			ndl++;
			if (needle[ndl] == '\0')
				return ((char *)&(haystack[hay]));
		}
		hay++;
	}
	return (NULL);
}
