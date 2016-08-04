/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 14:04:18 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/04 13:25:16 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "bool.h"

# define REP "0123456789abcdef"

int	ft_printf(const char *format, ...);
int	ft_putstr_case(const char *str, t_bool upp_case);

#endif
