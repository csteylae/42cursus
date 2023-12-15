/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:19:52 by csteylae          #+#    #+#             */
/*   Updated: 2023/12/06 13:21:28 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*rm_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	str = str + i;
	return (str);
}

static int	is_valid_sign(const char *str)
{
	int	i;
	int	minus;
	int	count;

	i = 0;
	minus = 0;
	count = 0;
	while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
		{
			minus++;
			count++;
		}
		if (str[i] == '+')
			count++;
		if (count > 1)
			return (-1);
		i++;
	}
	return (minus);
}

static const char	*skip_signs_and_zero(const char*str)
{
	int	i;

	i = 0;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0' && str[i + 1] != '\0')
		i++;
	str = str + i;
	return (str);
}

long	ft_atol(const char *str)
{
	long long	nb;
	int			i;
	int			minus;

	nb = 0;
	i = 0;
	str = rm_space(str);
	minus = is_valid_sign(str);
	if (minus == -1)
		return (0);
	str = skip_signs_and_zero(str);
	while (str[i] != '\0' && ft_isdigit(str[i]) == 1)
	{
		nb = nb * 10 + (str[i] - 48);
		if (nb < 0 && minus == 1)
			return (0);
		if (minus == 0 && i >= 19)
			return (-1);
		i++;
	}
	if (minus == 1)
		nb = -nb;
	return (nb);
}
