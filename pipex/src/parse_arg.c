/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:31:56 by csteylae          #+#    #+#             */
/*   Updated: 2024/04/16 11:45:06 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_verify_envp(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		ft_puterror(NULL, "environ not found\n", NULL);
	while (envp[i] && !ft_is_equal(PATH, envp[i]))
		i++;
	if (!envp[i] || !ft_strlen(envp[i]))
		ft_puterror(NULL, "environ not found\n", NULL);
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
	path = envp[i] + ft_strlen(PATH);
	path_array = ft_split(path, ':');
	if (!path_array)
		return (NULL);
	return (path_array);
}

char **ft_is_absolute_path(char *cmd_name)
{
	char **path_array;

	path_array = NULL;
	if (ft_strchr(cmd_name, '/') != NULL)
	{
		path_array = ft_split(cmd_name, ' ');
		if (!path_array)
			return (NULL);
	}
	return (path_array);
}

char	**ft_get_path(char *cmd_name, char **envp)
{
	char	**path_array;
	char 	*cmd;
	int		i;
	
	i = 0;
	if ((path_array = ft_is_absolute_path(cmd_name)))
		return (path_array);
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

	//if (ft_strchr(argv, '"')) // for echo , etc
	cmd = ft_split(argv, ' ');
	if (!cmd)
		return (NULL);
	return (cmd);
}
