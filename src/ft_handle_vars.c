/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 15:26:41 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/18 15:59:36 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "defs.h"

static char		**ft_split_vars(char *str, int count)
{
	int		vari;
	int		stri;
	char	**ret;

	stri = 0;
	vari = 0;
	ret = NULL;
	if ((ret = (char **)malloc(sizeof(char *) * (count + 1))) == NULL)
		return (NULL);
	ret[count] = NULL;
	while (str[stri] != '\0' && vari < count)
	{
		if (str[stri] == '$')
		{
			if (ft_var(&(ret[vari]), str + stri) == FALSE)
			{
				ft_del_args(&ret);
				return (NULL);
			}
			stri++;
			while (ft_isdelim(str[stri]) == FALSE)
				stri++;
			vari++;
		}
	}
	return (ret);
}

t_bool			ft_handle_vars(char **arg)
{
	int		i;
	int		count;
	char	tmp;
	char	**vars;

	i = 0;
	count = 0;
	vars = NULL;
	tmp = NULL;
	while ((*arg)[i] != '\0')
	{
		if ((*arg)[i] == '$')
			count++;
		i++;
	}
	if (count > 0)
		if ((vars = ft_split_vars(*arg, count)) == NULL)
			return (FALSE);
	ft_join_vars(&tmp, *arg, vars);
	ft_del_args(&vars);
	if (tmp == NULL)
		return (FALSE);
	free(*arg);
	(*arg) = tmp;
	return (TRUE);
}
