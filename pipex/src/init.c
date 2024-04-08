/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:52:03 by csteylae          #+#    #+#             */
/*   Updated: 2024/04/05 12:10:41 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

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
	if (!ft_strlen(envp[i]))
		return (NULL);
	path = envp[i] + ft_strlen(PATH);
	path_array = ft_split(path, ':');
	if (!path_array)
		return (NULL);
	return (path_array);
}

char	**ft_get_path(char *cmd_name, char **envp)
{
	char	**path_array;
	char 	*cmd;
	int		i;
	
	i = 0;
	path_array = ft_parse_envp(envp);
	if (!path_array)
		return (NULL);
	cmd = ft_strjoin("/", cmd_name, NO_MALLOC); 
	if (!cmd)
		return (NULL);
	while (path_array[i])
	{
		path_array[i] = ft_strjoin(path_array[i], cmd, S1_MALLOC);
		if (!path_array[i])
			return (free(cmd), NULL);
		i++;
	}	
	free(cmd);
	return (path_array);
}

char	**ft_get_cmd(char *argv)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		return (NULL);
	return (cmd);
}

void	ft_find_path(char **path, char **cmd, char **envp)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (access(path[i], F_OK) == 0)
			execve(path[i], cmd, envp);
		i++;
	}
	ft_printf("error cmd not found\n");
}
