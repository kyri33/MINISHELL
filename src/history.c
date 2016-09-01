/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 16:53:16 by kioulian          #+#    #+#             */
/*   Updated: 2016/09/01 16:03:08 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

char   	**ft_addhistory(char **tab, char *str)
{
	char   	**temp;
	int    		i;
	int    		x;

	i = 0;
	x = 0;
	temp = (char **)malloc(sizeof(char*) * 11);
	temp[i] = ft_strdup(str);
	i++;
	while (i < 10)
	{
		if (tab[x])
			temp[i] = ft_strdup(tab[x]);
		else
			temp[i] = 0;
		i++;
		x++;
	}
	free_tab(tab);
	return (temp);
}

void	ft_clear(t_to *to)
{
	int	i;

	i = 0;
	ft_cursorend(to);
	while (i < to->max_x + to->prompt + 1)
	{
		tputs(tgetstr("le", NULL), 1, ft_ft_putchar);
		tputs(" ", 1, ft_ft_putchar);
		tputs(tgetstr("le", NULL), 1, ft_ft_putchar);
		i++;
	}
	to->max_x = 0;
	to->x = 0;
}

char	*ft_histup(t_to *to, char *line)
{
	if (to->y < 10)
	{
		if (to->history[to->y])
		{
			free(line);
			to->old_x = ft_strlen(to->history[to->y]);
			to->y++;
			ft_clear(to);
			return (ft_strdup(to->history[to->y - 1]));
		}
	}
	return (line);
}

char	*ft_histdown(t_to *to, char *line)
{
	if (to->y > 0)
	{
		to->y--;
		if (to->history[to->y - 1])
		{
			free(line);
			to->old_x = ft_strlen(to->history[to->y - 1]);
			ft_clear(to);
			return (ft_strdup(to->history[to->y - 1]));
		}
	}
	return (line);
}
