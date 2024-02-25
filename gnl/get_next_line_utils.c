#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i = 0;
	while (str[i])
		i++;
	return(i);
}

char	*ft_strchr(char *str, char c)
{
	size_t	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}


char *ft_memcpy(char *dst, char *src, size_t len)
{
	size_t	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}


char	*ft_strjoin(char *s1, char *s2)
{
	char *line = NULL;
	size_t len_s2 = ft_strlen(s2);
	size_t len = ft_strlen(s1) + len_s2;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
	{
		free(s1);
		s1 = NULL;
		return (NULL);
	}
	ft_memcpy(line, s1, ft_strlen(s1));
	ft_memcpy(line + ft_strlen(s1), s2, len_s2);
	line[len] = '\0';
	free(s1);
	return (line);
}

