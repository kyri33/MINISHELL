/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:25:31 by khamusek          #+#    #+#             */
/*   Updated: 2016/07/08 13:27:08 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "defs.h"

void	ft_del_args(char ***argv)
{
	int		i;

	i = 0;
	if (*argv == NULL)
		return ;
	while ((*argv)[i] != NULL)
	{
		free((*argv)[i]);
		i++;
	}
	if (*argv != NULL)
		free(*argv);
	*argv = NULL;
}
