/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 18:15:05 by kioulian          #+#    #+#             */
/*   Updated: 2016/10/25 18:16:23 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_c(int signum)
{
	ft_putnbr(signum);
	if (PID > 0)
	{
		ft_putchar('\n');
		kill(PID, SIGKILL);
	}
	else
		ft_putstr("\nPlease use the 'exit' command to quit\n$> ");
}
