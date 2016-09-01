/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termios.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 16:19:05 by kioulian          #+#    #+#             */
/*   Updated: 2016/09/01 16:02:52 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

int		ft_add(char c, char **line, t_to *to)
{
	if (!(*line))
		*line = ft_strnew(1);
	*line = ft_addchar(*line, c);
	to->x++;
	to->max_x++;
	return (1);
}

int		ft_newline(t_to *to, char **line)
{
	ft_putstr("\n");
	if (*line && *line[0])
		to->history = ft_addhistory(to->history, *line);
	to->x = 0;
	to->y = 0;
	to->max_x = 0;
	return (0);
}

void	ft_showline(char *line, t_to *to)
{
	int	i;

	i = 0;
	if (!to->old_x)
		to->old_x = to->x;
	ft_clear(to);
	//tputs("21$h > ", 1, ft_ft_putchar);
	ft_printf("%s%s%s@%s21sh$%s ", CCYN, ft_get_user(), CNRM, CMAG, CNRM);
	tputs(line, 1, ft_ft_putchar);
	if (line)
		to->max_x = ft_strlen(line);
	to->x = to->max_x;
	ft_replace_cursor(to);
}

int		ft_backspace(t_to *to, char **line)
{
	if (to->x > 0)
	{
		to->x--;
		*line = ft_removechar(to, *line, to->x);
		return (1);
	}
	return (0);
}

int		ft_getline(char **line, t_to *to)
{
	char	b[6];
	int		check;

	while (1)
	{
		check = 0;
		ft_strclr(b);
		read(0, b, 6);
		if (ft_isprint(b[0]))
			check = ft_add(b[0], line, to);
		else if (b[0] == 10)
			return (ft_newline(to, line));
		else if (b[0] == 27 && b[1] == 91 && b[2] != 51)
			check = ft_move_cursor(b[2], to, line);
		else if (b[0] == 127)
			check = ft_backspace(to, line);
		else
		{
			int	i = 0;
			while (b[i])
			{
				ft_putnbr(b[i]);
				ft_putchar(' ');
				i++;
			}
		}
		if (check)
			ft_showline(*line, to);
	}
}
