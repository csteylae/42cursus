/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:55:26 by csteylae          #+#    #+#             */
/*   Updated: 2024/04/25 17:37:02 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	**ft_get_cmd(char *argv)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		return (NULL);
	return (cmd);
}

char	**ft_parse_envp(char **envp)
{
	char	**path_array;
	char	*path;
	int		i;

	path_array = NULL;
	path = NULL;
	i = 0;
	while (envp[i] && !ft_is_equal(PATH, envp[i]))
		i++;
	if (!envp[i])
		return (NULL);
	path = envp[i] + ft_strlen(PATH);
	if (!path)
		return (NULL);
	path_array = ft_split(path, ':');
	if (!path_array)
		return (NULL);
	return (path_array);
}

char	**ft_add_cmd_path(char *cmd_arg, char **path_array)
{
	int	i;

	i = 0;
	cmd_arg = ft_strjoin("/", cmd_arg, NO_MALLOC);
	if (!cmd_arg)
	{
		ft_memfree(path_array);
		return (NULL);
	}
	while (path_array[i])
	{
		path_array[i] = ft_strjoin(path_array[i], cmd_arg, S1_MALLOC);
		if (!path_array[i])
			return (ft_memfree(path_array), free(cmd_arg), NULL);
		i++;
	}
	free(cmd_arg);
	return (path_array);
}

char	**ft_get_path(char *cmd_name, char **envp)
{
	char	**path_array;
	int		i;

	i = 0;
	path_array = ft_is_absolute_path(cmd_name);
	if (path_array)
		return (path_array);
	path_array = ft_parse_envp(envp);
	if (!path_array)
		return (NULL);
	path_array = ft_add_cmd_path(cmd_name, path_array);
	return (path_array);
}

void	ft_find_path(char **path, char **cmd, char **envp)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (access(path[i], X_OK) == 0)
		{
			if (execve(path[i], cmd, envp) < 0)
				return ;
		}
		else
			i++;
	}
}
