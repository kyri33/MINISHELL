/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 16:45:07 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/22 16:45:09 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

char	*ft_strjoin_path(char *path, char *cmd)
{
	char	*tmp;
	char	*ret;

	ret = NULL;
	if ((tmp = ft_strjoin(path, "/")) == NULL)
		return (NULL);
	ret = ft_strjoin(tmp, cmd);
	free(tmp);
	return (ret);
}
