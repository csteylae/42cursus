/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:43:53 by csteylae          #+#    #+#             */
/*   Updated: 2024/04/01 21:14:10 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		len;
	char		*dest;
	size_t		i;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	while (i < len)
	{
		dest[i] = *((char *)s1 + i);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
