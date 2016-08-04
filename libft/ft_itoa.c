/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 12:03:35 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/04 12:43:08 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;

	sign = 0;
	str = ((char *)malloc(sizeof(char) * 50)) + 48;
	str[1] = '\0';
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	(*str) = "0123456789"[n % 10];
	n /= 10;
	while (n != 0)
	{
		str--;
		(*str) = "0123456789"[n % 10];
		n /= 10;
	}
	if (sign == 1)
	{
		str--;
		(*str) = '-';
	}
	return (str);
}
