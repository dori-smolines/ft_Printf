/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:59:36 by smolines          #+#    #+#             */
/*   Updated: 2023/11/30 10:59:39 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *str, ...);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_hexa_unsigned(long unsigned int nbr, char *base);
int	ft_putnbr_unsigned_fd(unsigned int n, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putnb_ptr(unsigned long long ptr);

#endif
