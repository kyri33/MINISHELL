/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:24:44 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/04 13:46:22 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "defs.h"

t_bool			ft_fill_args(char **cmd, char ***argv)
{
	if (((*argv) = ft_strsplit(*cmd, ' ')) == NULL)
		return (FALSE);
	return (TRUE);
}
