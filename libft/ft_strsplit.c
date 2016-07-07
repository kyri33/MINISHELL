/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 11:35:53 by khamusek          #+#    #+#             */
/*   Updated: 2016/05/14 11:41:55 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int		ft_numwords(const char *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			words++;
		i++;
	}
	return (words + 1);
}

static int		ft_wordlen(const char *s, char c)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		words;
	int		src;
	int		len;
	char	**arr;

	i = 0;
	src = 0;
	words = ft_numwords(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	while (i < words)
	{
		len = ft_wordlen(&(s[src]), c);
		arr[i] = ft_strsub(s, (unsigned int)src, len);
		if (!(arr[i]))
			return (NULL);
		src = src + len + 1;
		i++;
	}
	arr[i] = 0;
	return (arr);
}
