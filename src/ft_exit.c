/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:25:55 by khamusek          #+#    #+#             */
/*   Updated: 2016/07/08 13:25:56 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

void	ft_exit(char **cmd, int status, char *err)
{
	struct termios	term;

	if (*cmd != NULL)
		free(*cmd);
	if (status == EXIT_FAILURE)
		ft_putendl_fd(err, STDERR);
	if (tcgetattr(0, &term) == -1)
		exit(EXIT_FAILURE);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		exit(EXIT_FAILURE);
	exit(status);
}
