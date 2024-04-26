/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:57:19 by csteylae          #+#    #+#             */
/*   Updated: 2024/04/25 17:06:02 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_memfree(char **array_ptr)
{
	int	index;

	index = 0;
	while (array_ptr[index])
		index++;
	while (index >= 0)
	{
		free(array_ptr[index]);
		index--;
	}
	free(array_ptr);
	array_ptr = NULL;
}

void	ft_free_struct(t_pipex **ptr)
{
	if (!ptr || ! *ptr)
		return ;
	if ((*ptr)->path)
		ft_memfree((*ptr)->path);
	if ((*ptr)->cmd)
		ft_memfree((*ptr)->cmd);
	if ((*ptr)->fd_in >= 0)
		close((*ptr)->fd_in);
	if ((*ptr)->fd_out >= 0)
		close((*ptr)->fd_out);
	free(*ptr);
}

void	ft_puterror(char *argv, char *msg, t_pipex **ptr)
{
	if (argv)
		ft_printf("%s :", argv);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_free_struct(ptr);
	exit(EXIT_FAILURE);
}

int	ft_is_equal(char *s1, char *s2)
{
	if (!ft_strncmp(s1, s2, ft_strlen(s1)))
		return (1);
	return (0);
}

char	**ft_is_absolute_path(char *cmd_name)
{
	char	**path_array;

	path_array = NULL;
	if (ft_strchr(cmd_name, '/') != NULL)
	{
		path_array = ft_split(cmd_name, ' ');
		if (!path_array)
			return (NULL);
	}
	return (path_array);
}
