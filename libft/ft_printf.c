/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 13:22:33 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/04 13:22:00 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

static void	ft_print_sign(int *nbr, int *len, int sign)
{
	if (*nbr < 0)
	{
		if (sign == 1)
		{
			ft_putchar('-');
			(*len)++;
		}
		(*nbr) *= -1;
	}
}

static int	ft_base_convert(int nbr, int base, const char conv_case, int sign)
{
	char		*buff;
	char		*pos;
	int			len;

	len = 0;
	buff = (char *)malloc(sizeof(*buff) * 50);
	pos = &buff[49];
	ft_print_sign(&nbr, &len, sign);
	*pos = '\0';
	pos--;
	*pos = REP[nbr % base];
	nbr /= base;
	while (nbr > 0)
	{
		pos--;
		*pos = REP[nbr % base];
		nbr /= base;
	}
	len += ft_putstr_case(pos, conv_case == ft_toupper(conv_case));
	free(buff);
	return (len);
}

static int	ft_str_convert(const char *format, unsigned int index,
		va_list *args)
{
	void	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (format[index] == 's')
	{
		str = va_arg(*args, char *);
		ft_putstr((char *)str);
		len = ft_strlen((char *)str);
	}
	else
	{
		str = (wchar_t *)va_arg(*args, wchar_t *);
		while (((wchar_t *)(str))[i] != L'\0')
		{
			ft_putchar((char)(((wchar_t *)(str))[i]));
			i++;
			len++;
		}
	}
	return (len);
}

static int	ft_convert(const char *format, unsigned int index,
		va_list *args)
{
	int		ret;

	ret = 1;
	if (format[index] == 's' || format[index] == 'S')
		ret = ft_str_convert((const void *)format, index, args);
	else if (format[index] == 'c' || format[index] == 'C')
		ft_putchar((unsigned char)va_arg(*args, int));
	else if (format[index] == 'd' || format[index] == 'D'
			|| format[index] == 'i')
		ret = ft_base_convert(va_arg(*args, int), 10, format[index], 1);
	else if (format[index] == 'o' || format[index] == 'O')
		ret = ft_base_convert(va_arg(*args, unsigned int),
				8, format[index], 0);
	else if (format[index] == 'x' || format[index] == 'X')
		ret = ft_base_convert(va_arg(*args, unsigned int),
				16, format[index], 0);
	else if (format[index] == 'u' || format[index] == 'U')
		ret = ft_base_convert(va_arg(*args, unsigned int),
				10, format[index], 0);
	else if (format[index] == 'p')
		ret = ft_base_convert((unsigned int)va_arg(*args, void *), 16,
				format[index], 0);
	else if (format[index] == '%')
		ft_putchar('%');
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	index;
	int				len;

	index = 0;
	len = 0;
	va_start(args, format);
	while (format[index] != '\0')
	{
		if (format[index] != '%')
		{
			len++;
			ft_putchar(format[index]);
		}
		else
		{
			index++;
			len += ft_convert(format, index, &args);
		}
		index++;
	}
	va_end(args);
	return (len);
}
