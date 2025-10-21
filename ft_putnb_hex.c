/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:00:23 by smolines          #+#    #+#             */
/*   Updated: 2023/11/30 11:00:25 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_hexa(long unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i = 1;
	while (nb != 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_putnbr_hexa_unsigned(long unsigned int nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr >= 16)
		ft_putnbr_hexa_unsigned(nbr / 16, base);
	ft_putchar_fd (base[nbr % 16], STDOUT_FILENO);
	return (ft_len_hexa(nbr));
}
