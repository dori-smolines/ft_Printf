/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb_prt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:00:37 by smolines          #+#    #+#             */
/*   Updated: 2023/11/30 11:00:39 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft2_len_hexa(unsigned long long nb)
{
	int	i;

	i = 0;
	while (nb)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

static void	ft2_putnbr_hexa_unsigned(unsigned long long nbr, char *base)
{
	if (nbr >= 16)
		ft2_putnbr_hexa_unsigned(nbr / 16, base);
	ft_putchar_fd (base[nbr % 16], STDOUT_FILENO);
}

int	ft_putnb_ptr(unsigned long long ptr)
{
	int	i;

	i = 2;
	if (!ptr)
	{
		write(STDOUT_FILENO, "(nil)", 5);
		return (5);
	}
	else
	{
		write(STDOUT_FILENO, "0x", 2);
		ft2_putnbr_hexa_unsigned(ptr, "0123456789abcdef");
		i += ft2_len_hexa(ptr);
	}
	return (i);
}
