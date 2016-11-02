/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 18:15:05 by kioulian          #+#    #+#             */
/*   Updated: 2016/11/02 13:45:03 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_c(int signum)
{
	(void)signum;
	if (g_pid > 0)
	{
		ft_putchar('\n');
		kill(g_pid, SIGKILL);
	}
	else
		ft_putstr("\nPlease use the 'exit' command to quit\n$> ");
}
