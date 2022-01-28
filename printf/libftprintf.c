/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:04:52 by ccalas            #+#    #+#             */
/*   Updated: 2021/12/13 15:04:47 by ccalas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len = len + ft_convertion(ap, format[i]);
		}
		else
			len = len + ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

int	ft_convertion(va_list ap, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = len + ft_putchar(va_arg(ap, int));
	else if (c == 's')
		len = len + ft_putstr(va_arg(ap, char *));
	else if (c == '%')
		len = len + ft_putchar('%');
	else if (c == 'd' || c == 'i')
		len = len + ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		len = len + ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
	{
		if (c == 'x')
			len = len + ft_putnbr_base(va_arg(ap, int), "0123456789abcdef");
		else if (c == 'X')
			len = len + ft_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
	}
	else if (c == 'p')
		len = len + ft_putstr_p(va_arg(ap, uintptr_t));
	return (len);
}
