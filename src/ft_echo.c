/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:24:19 by khamusek          #+#    #+#             */
/*   Updated: 2016/07/08 16:38:11 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "libft.h"
#include "defs.h"

void	ft_echo(char **cmd)
{
	int		i;
	char	**argv;

	argv = NULL;
	i = 1;
	if (ft_fill_args(cmd, &argv) == TRUE)
	{
		while (argv[i] != NULL)
		{
			ft_putstr(argv[i]);
			if (argv[i + 1] != NULL)
				ft_putstr(" ");
			i++;
		}
		ft_putendl("");
	}
	else
		ft_error("There was an unexpected error executing the\
				command", "echo");
	ft_del_args(&argv);
}
