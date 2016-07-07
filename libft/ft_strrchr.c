/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 11:43:32 by khamusek          #+#    #+#             */
/*   Updated: 2016/05/14 11:43:34 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*i;

	i = (char *)&(s[ft_strlen(s)]);
	if ((int)*i == c)
		return (i);
	i--;
	while (*i != '\0')
	{
		if ((int)*i == c)
			return (i);
		i--;
	}
	return (NULL);
}
