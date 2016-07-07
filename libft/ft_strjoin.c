/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 11:46:37 by khamusek          #+#    #+#             */
/*   Updated: 2016/05/14 11:46:39 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1)
                + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
        ft_strcpy(dest, s1);
        ft_strcat(dest, s2);
	return (dest);
}
