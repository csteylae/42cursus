#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H	

# include <stdlib.h>
# include <unistd.h>

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE > 1000000
#   undef BUFFER_SIZE
#	endif
# endif 

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 1
#   undef BUFFER_SIZE
#   endif
# endif
  
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, char c);
char	*ft_memcpy(char *dst, char *src, size_t len);
char	*ft_strjoin(char *str, char *tab);
char	*init_line(char *tab);
char	*ft_readline(char *line, int fd);
void	update_next_line(char *line, char *next_line);
char	*create_line(char *line);
char	*get_next_line(int fd);

#endif 
