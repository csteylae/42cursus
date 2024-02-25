#include "get_next_line.h"
#include <fcntl.h>

char	*init_line(char *tab)
{
	size_t	i = 0;
	char *line = NULL;
	line = (char*)malloc(sizeof(char) * (ft_strlen(tab) + 1));
	if (!line)
		return (NULL);
	while (tab[i])
	{
		line[i] = tab[i];
		i++;
	}
	line[i] = '\0';
	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		tab[i] = '\0';
		i++;
	}
	return (line);
}

char	*ft_readline(char *line, int fd)
{
	int	bytes_read = 1;
	char buffer[BUFFER_SIZE + 1] = "";

	while (bytes_read != 0 && !ft_strchr(line, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(line);
			line = NULL;
			return (line);
		}
		buffer[bytes_read] = '\0';
		if (bytes_read == 0)
			break;
		line = ft_strjoin(line, buffer);
		if (!line)
		{
			free(line);
			line = NULL;
			return (NULL);
		}
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		line = NULL;
	}
	return(line);
}

void	update_next_line(char *line, char *next_line)
{
	size_t	i = 0;

	line = ft_strchr(line, '\n');
	if (!line)
		return;
	line = line + 1;
	i = ft_strlen(line);
	ft_memcpy(next_line, line, i);
}

char *create_line(char *line)
{
	size_t i = 0;
	char *new_line = NULL;

	while(line[i]  && line[i] != '\n')
		i++;
	i+= 1;
	if (!ft_strchr(line, '\n'))
		i = i -1;
	new_line = (char*)malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return(NULL);
	ft_memcpy(new_line, line, i);
	free(line);
	new_line[i] = '\0';
	return (new_line);
}

char *get_next_line(int fd)
{
	static char next_line[BUFFER_SIZE + 1] = "";
	char *line = NULL;

	if (fd < 0)
		return (NULL);
	line = init_line(next_line);
	if (!line)
		return (NULL);
	line = ft_readline(line, fd);
	if (!line)
	{
		free(line);
		return(NULL);
	}
	update_next_line(line, next_line);
	line = create_line(line);
	if (!line)
	{
		free(line);
		return(NULL);
	}
	return(line);
}

/*
#include <fcntl.h>
#include <stdio.h>
int main(int argc, char **argv)
{
   int fd = open("1char.txt", O_RDONLY);
//    int fd = open("file3.txt", O_RDONLY);
    (void)argc;
    (void)argv;
     char *str = NULL;
   str = get_next_line(fd);
   printf("%s", str);
   free(str);
   while(str)
   {
       str = get_next_line(fd);
       printf("%s", str);
       free(str);
   }
   return(0);
}
*/
/*  
#include <stdio.h>

int main(void)
{
	char *str = NULL;
	int fd = open("test.txt", O_RDONLY);
	printf("%s\n", str =  get_next_line(fd));
	free(str);
	str = NULL;
	printf("%s\n", str =  get_next_line(fd));
	free(str);
	printf("%s\n", str =  get_next_line(fd));
	free(str);
	str = NULL;
	printf("%s\n",str );
	return (0);
}
*/






	
