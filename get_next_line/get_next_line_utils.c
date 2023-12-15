/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:00:08 by csteylae          #+#    #+#             */
/*   Updated: 2023/11/15 18:14:59 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_memfree(char *ptr)
{
	free(ptr);
	ptr = NULL;
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (len == 0)
		return (dst);
	while (i < len)
	{
		*((unsigned char *) dst + i) = *((unsigned char *) src + i); 
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (ft_memfree(s1));
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2));
	str[len] = '\0';
	ft_memfree(s1);
	return (str);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (c == s[i])
		return (s + i);
	else
		return (0);
}
