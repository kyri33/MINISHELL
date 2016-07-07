/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 12:04:09 by khamusek          #+#    #+#             */
/*   Updated: 2016/05/14 12:04:10 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	if (((unsigned int)c >= 'A' && (unsigned int)c <= 'Z') ||
			((unsigned int)c >= 'a' && (unsigned int)c <= 'z'))
		return (1);
	else
		return (0);
}
