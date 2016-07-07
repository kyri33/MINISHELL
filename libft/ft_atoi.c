/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 12:07:08 by khamusek          #+#    #+#             */
/*   Updated: 2016/05/14 12:07:10 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		num;

	sign = 1;
	num = 0;
	i = 0;
	while (ft_isdigit((int)nptr[i]) == 0 && nptr[i] != '-' &&
			nptr[i] != '+')
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] != '\0' && ft_isdigit((int)nptr[i]) != 0)
	{
		num = num * 10;
		num = num + (int)nptr[i] - '0';
		i++;
	}
	return (num * sign);
}
