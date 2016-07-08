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

#include <stdlib.h>
#include "defs.h"

void	ft_exit(char **cmd, int status, char *err)
{
	if (*cmd != NULL)
		free(*cmd);
	if (status == EXIT_FAILURE)
		ft_putendl_fd(err, STDERR);
	exit(status);
}
