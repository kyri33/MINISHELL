/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 11:35:53 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/04 12:45:17 by khamusek         ###   ########.fr       */
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
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int		ft_wordlen(const char *s, char c)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
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
		len = ft_wordlen(s + src, c);
		arr[i] = ft_strsub(s, (unsigned int)src, len);
		if (!(arr[i]))
			return (NULL);
		src = src + len;
		while (s[src] == c && s[src] != '\0')
			src++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
