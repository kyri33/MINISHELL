/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:24:44 by khamusek          #+#    #+#             */
/*   Updated: 2016/07/08 14:01:14 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "defs.h"

static int		ft_num_words(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == ' ' || str[i] == '\t') && str[i - 1] != ' ' &&
				str[i - 1] != '\t')
			count++;
		i++;
	}
	if (str[i] == '\0' && str[i - 1] != ' ' && str[i - 1] != '\t')
		count++;
	return (count);
}

static int		ft_wordlen(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static t_bool	ft_split(char **cmd, char ***argv)
{
	int		i;
	int		src;
	int		words;
	int		len;

	i = 0;
	src = 0;
	words = ft_num_words(*cmd);
	if ((*argv = (char **)malloc(sizeof(char *) * (words + 1))) == NULL)
		return (FALSE);
	while (i < words)
	{
		while ((*cmd)[src] == ' ' || (*cmd)[src] == '\t')
			src++;
		len = ft_wordlen(&((*cmd)[src]));
		if (((*argv)[i] = ft_strsub(*cmd, (unsigned int)src, len))
				== NULL)
			return (FALSE);
		src = src + len + 1;
		i++;
	}
	(*argv)[i] = NULL;
	return (TRUE);
}

t_bool			ft_fill_args(char **cmd, char ***argv)
{
	if (ft_split(cmd, argv) == FALSE)
		return (FALSE);
	return (TRUE);
}
