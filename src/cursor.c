/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 11:11:10 by kioulian          #+#    #+#             */
/*   Updated: 2016/09/01 15:46:27 by dnematan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

int	ft_move_left(t_to *to)
{
	if (to->x > 0)
	{
		to->x--;
		tputs(tgetstr("le", NULL), 1, ft_ft_putchar);
	}
	return (0);
}

int	ft_move_right(t_to *to)
{
	if (to->x < to->max_x)
	{
		to->x++;
		tputs(tgetstr("nd", NULL), 1, ft_ft_putchar);
	}
	return (0);
}

int	ft_cursorend(t_to *to)
{
	int	i;

	i = to->x - 1;
	while (++i < to->max_x)
		tputs(tgetstr("nd", NULL), 1, ft_ft_putchar);
	return (0);
}

int	ft_replace_cursor(t_to *to)
{
	while (to->old_x < to->x)
		ft_move_left(to);
	if (to->old_x > to->x)
		to->x = to->max_x;
	to->old_x = 0;
	return (0);
}

int	ft_move_cursor(char c, t_to *to, char **line)
{
	if (c == 68)
		return (ft_move_left(to));
	else if (c == 67)
		return (ft_move_right(to));
	else if (c == 72) // home
		;
	else if (c == 65)
	{
		*line = ft_histup(to, *line);
		return (1);
	}
	else if (c == 66)
	{
		*line = ft_histdown(to, *line);
		return (1);
	}
	else if (c == 70)
		return (ft_cursorend(to));
	return (0);
}
