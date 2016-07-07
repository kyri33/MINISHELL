/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 11:40:05 by khamusek          #+#    #+#             */
/*   Updated: 2016/05/14 11:40:13 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_isspace(const char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

int		ft_spaces(const char *s)
{
	int		spaces;
	int		i;

	spaces = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isspace(s[i]) == 1)
			spaces++;
		i++;
	}
	return (spaces);
}

char	*ft_strtrim(char const *s)
{
	int		dst;
	int		src;
	char	*dest;

	dst = 0;
	src = 0;
	dest = ft_strnew(ft_strlen(s) - ft_spaces(s));
	if (!dest)
		return (NULL);
	while (s[src] != '\0')
	{
		while (ft_isspace(s[src]) == 1)
			src++;
		dest[dst] = s[src];
		dst++;
		src++;
	}
	return (dest);
}
