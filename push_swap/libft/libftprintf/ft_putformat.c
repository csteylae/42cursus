/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:50:39 by csteylae          #+#    #+#             */
/*   Updated: 2023/10/17 19:35:22 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putnbr_base(long nb, int len, char *base)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		nb = -nb;
		if (ft_putchar('-') == -1)
			return (-1);
		i++;
	}
	if (nb > len - 1)
		i += ft_putnbr_base(nb / len, len, base);
	if (ft_putchar(base[nb % len]) == -1)
		return (-1);
	return (i);
}

int	ft_putnbr_unsigned(unsigned long nb, unsigned long len, char *base)
{
	int	i;

	i = 1;
	if (!base || len == 1)
		return (-1);
	if (nb > len - 1)
		i += ft_putnbr_unsigned(nb / len, len, base);
	if (ft_putchar(base[nb % len]) == -1)
		return (-3);
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str || str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		if (ft_putchar(str[i]) == -1)
			return (-1);
		i++;
	}
	if (i == 0)
		return (0);
	return (i);
}
