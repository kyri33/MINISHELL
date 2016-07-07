/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 11:44:14 by khamusek          #+#    #+#             */
/*   Updated: 2016/05/14 11:44:16 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && (unsigned char)(s1[i]) == (unsigned char)(s2[i])
			&& i < (n - 1))
		i++;
	if ((unsigned char)(s1[i]) == (unsigned char)(s2[i]))
		return (1);
	else
		return (0);
}
