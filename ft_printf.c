/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:59:15 by smolines          #+#    #+#             */
/*   Updated: 2023/11/30 10:59:21 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list ap, const char format)
{
	int	len_format;

	len_format = 0;
	if (format == 'c')
		len_format += ft_putchar_fd(va_arg(ap, int), STDOUT_FILENO);
	if (format == 's')
		len_format += ft_putstr_fd(va_arg(ap, char *), STDOUT_FILENO);
	if (format == 'p')
		len_format += ft_putnb_ptr(va_arg(ap, unsigned long long));
	if ((format == 'd') || (format == 'i'))
		len_format += ft_putnbr_fd(va_arg(ap, int), STDOUT_FILENO);
	if (format == 'u')
		len_format += ft_putnbr_unsigned_fd(va_arg(ap, unsigned int),
				STDOUT_FILENO);
	if (format == 'x')
		len_format += ft_putnbr_hexa_unsigned(va_arg(ap, unsigned int),
				"0123456789abcdef");
	if (format == 'X')
		len_format += ft_putnbr_hexa_unsigned(va_arg(ap, unsigned int),
				"0123456789ABCDEF");
	if (format == '%')
		len_format += ft_putchar_fd('%', STDOUT_FILENO);
	return (len_format);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			len = len + ft_putchar_fd (str[i], 1);
			i++;
		}
		else
		{
			len = len + ft_format(ap, str[i + 1]);
			i += 2;
		}
	}
	va_end(ap);
	return (len);
}
