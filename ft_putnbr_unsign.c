/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:23:26 by smolines          #+#    #+#             */
/*   Updated: 2023/11/15 09:23:28 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_putnbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i = 1;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	int	i;

	i = 0;
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10 + '0'), fd);
	return (ft_len_putnbr(n));
}
