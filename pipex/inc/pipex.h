/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:08:11 by csteylae          #+#    #+#             */
/*   Updated: 2024/04/16 11:10:59 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/**************** Libraries  *************/

# include "../lib/libft/libft.h"
# include "../lib/libft/ft_printf/ft_printf.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

/***************  Macros *****************/

# define READ_FROM 0
# define WRITE_TO 1
# define PATH "PATH="
# define MALLOC_ERROR "Malloc failed"


// my strjoin idk if its a good practice
# define S1_MALLOC '1'
# define S2_MALLOC '2'
# define BOTH_MALLOC '3'
# define NO_MALLOC '4'

/****************  STRUCT  *****************/
typedef	struct s_pipex
{
	char	**path;
	char	**cmd;
	char	**envp;
	int		fd_in;
	int		fd_out;
	int		len;
}	t_pipex;

/****************  Functions  **************/

//file init.c

void	ft_init_pipex(t_pipex **pipex, char *argv, char **envp);
void	ft_open_files(t_pipex **pipex, char **argv, int argc);

// file utils.c
void	ft_memfree(char **array_ptr);
void	*ft_puterror(char *argv, char *msg, t_pipex **elem);
int		ft_is_equal(char *s1, char *s2);
void	ft_print_struct(t_pipex *elem);

// file parse_arg.c
void	ft_verify_envp(char **envp);
char	**ft_parse_envp(char **envp);
char	**ft_get_path(char *argv, char **envp);
char	**ft_get_cmd(char *argv);
void	ft_find_path(char **path, char **cmd, char **envp);

//file pipex.c
void	*ft_pipex(int argc, char **argv, char **envp);

#endif
