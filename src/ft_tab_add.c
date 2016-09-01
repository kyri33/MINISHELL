/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 16:27:13 by kioulian          #+#    #+#             */
/*   Updated: 2016/08/27 16:51:35 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

char	**ft_tab_add(char **tab, char *str)
{
	char	**temp;
	int		i;
	int		x;

	i = 0;
	x = 0;
	temp = (char **)malloc(sizeof(char*) * 11);
	temp[i] = ft_strdup(str);
	i++;
	while (i < 10)
	{
		temp[i] = ft_strdup(tab[x]);
		i++;
		x++;
	}
	free_tab(tab);
	return (temp);
}
