/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 13:58:21 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/04 13:22:47 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_putstr_case(const char *str, t_bool upp_case)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (upp_case == FALSE)
			ft_putchar(str[i]);
		else
			ft_putchar(ft_toupper(str[i]));
		i++;
	}
	return (i);
}
