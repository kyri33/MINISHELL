/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:24:33 by khamusek          #+#    #+#             */
/*   Updated: 2016/07/08 13:24:35 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

void	ft_error(char *err, char *err_info)
{
	if (err_info == NULL)
		ft_putendl_fd(err, STDERR);
	else
	{
		ft_putstr_fd(err, STDERR);
		ft_putstr_fd(": ", STDERR);
		ft_putendl_fd(err_info, STDERR);
	}
}
