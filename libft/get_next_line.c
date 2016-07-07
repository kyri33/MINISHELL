/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 13:09:14 by khamusek          #+#    #+#             */
/*   Updated: 2016/07/03 14:51:44 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

static int	ft_buff_read(const int fd, char **buff)
{
	int		rd;
	char	*tmp1;
	char	*tmp2;
	char	*new_ln;

	new_ln = NULL;
	if (!(tmp1 = ft_strdup(*buff)))
		return (-1);
	if (!(tmp2 = ft_strnew(BUFF_SIZE)))
		return (-1);
	if ((rd = read(fd, (void *)tmp2, BUFF_SIZE)) < 0)
		return (-1);
	free(*buff);
	*buff = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
	new_ln = ft_strchr(*buff, '\n');
	if (new_ln == NULL && rd > 0)
		return (ft_buff_read(fd, buff));
	else if (new_ln == NULL && rd == 0 && ft_strlen(*buff) <= 0)
		return (0);
	else
		return (1);
}

static int	ft_read(const int fd, char **buff)
{
	int		rd;
	char	*new_ln;

	new_ln = NULL;
	if (!(*buff))
	{
		if (!(*buff = ft_strnew(BUFF_SIZE)))
			return (-1);
		if ((rd = read(fd, (void *)*buff, BUFF_SIZE)) < 0)
			return (-1);
		new_ln = ft_strchr(*buff, '\n');
		if (new_ln == NULL && rd > 0)
			return (ft_read(fd, &(*buff)));
		else if (new_ln == NULL && rd == 0 && ft_strlen(*buff) <= 0)
			return (0);
		else
			return (1);
	}
	else
		return (ft_buff_read(fd, &(*buff)));
}

static int	ft_fill_line(char **line, char **buff)
{
	char	*new_ln;
	char	*tmp;

	new_ln = ft_strchr(*buff, '\n');
	if (new_ln)
	{
		*new_ln = '\0';
		if (!(*line = ft_strdup(*buff)))
			return (-1);
		if (!(tmp = ft_strdup(new_ln + 1)))
			return (-1);
		*new_ln = '\n';
		free(*buff);
		*buff = tmp;
	}
	else
	{
		if (!(*line = ft_strdup(*buff)))
			return (-1);
		free(*buff);
		*buff = NULL;
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buff;
	int			rd;
	int			err;

	if ((rd = ft_read(fd, &buff)) < 0)
		return (-1);
	if (buff)
	{
		if ((err = ft_fill_line(line, &buff)) < 0)
			return (-1);
	}
	return (rd > 0);
}
