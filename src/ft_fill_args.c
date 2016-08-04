/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:24:44 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/04 13:46:22 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "defs.h"

static int		ft_num_words(char *str)
{
	int		i;
	int		count;
	t_bool	quote;

	i = 0;
	count = 0;
	quote = FALSE;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
			quote = !quote;
		if (((str[i] == ' ' || str[i] == '\t') && str[i - 1] != ' ' &&
				str[i - 1] != '\t') && quote == FALSE)
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
	t_bool	quote;

	i = 0;
	len = 0;
	quote = FALSE;
	while (((str[i] != ' ' && str[i] != '\t') || quote == TRUE) &&
			str[i] != '\0')
	{
		if (str[i] == '"')
			quote = !quote;
		else
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
		if ((*cmd)[src] == '"')
			src++;
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
