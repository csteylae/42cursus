//#include <gnl.h>

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


void	ft_memcpy(char *dst, char *src, size_t len)
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
	char line = NULL;
	size_t	i = 0;
	line = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!line)
	{
		free(s1);
		s1 = NULL;
		return (NULL);
	}
	ft_memcpy(line, s1, ft_strlen(s1));
	ft_memcpy(line + ft_strlen(s1), s2, ft_strlen(2));
	line[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (line);
}

