/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:30:36 by csteylae          #+#    #+#             */
/*   Updated: 2023/11/15 17:54:03 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

# include <unistd.h>
# include <stdlib.h>

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE > 1000000
#   undef BUFFER_SIZE
#  endif
# endif

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 1
#   undef BUFFER_SIZE
#  endif
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_memfree(char *ptr);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(void *dst, void *src, size_t len);
char	*ft_strchr(char *str, char c);
void	init_values(char **str, char *tab);
char	*create_line(char *str);
void	update_next_line_value(char *str, char *tab);
char	*read_until_end_of_line_or_eof(int fd, char *line);
#endif
