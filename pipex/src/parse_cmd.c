/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:04:25 by csteylae          #+#    #+#             */
/*   Updated: 2024/04/04 12:21:49 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//to do :
//now I have to parse cmd in order to execve crrectly
//
//Tommorrow I need to understand how the access() works, and then try execute something in that right way
//+ all the possibilities of behaviors of bash to see if my pipex works correctly and verifying all the possible errors returns of the differents functions
//I also need to verify all the possible errors that occur before the execution of execve and all the little subtilities about this, and
// I also have to parse the absolute path (for that purpose the binary tree)
// and finally I will check how to do to redirects the result of a command in a new file and how to implement pipes and fork
// Plus, I think that I have to manage the fact that the in and out file can be STDIN and STDOUT

#include "../inc/pipex.h"

char	**ft_parse_envp(char **envp)
{
	char	**path_array;
	char	*path;
	int		i;

	path_array = NULL;
	path = NULL;
	i = 0;
	if (!envp)
		return (NULL);
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

char	**ft_get_path(char **argv, char **envp)
{
	char	**path_array;
	char	*cmd;
	int		i;
	
	path_array = ft_parse_envp(envp);
	if (!path_array)
		return (NULL);
	cmd = ft_check_option_in_cmd(argv[2]);
	cmd = ft_strjoin("/", cmd, NO_MALLOC); 
	if (!cmd)
		return (ft_memfree(path_array), NULL);
	i = 0;
	while (path_array[i])
	{
		path_array[i] = ft_strjoin(path_array[i], cmd, S1_MALLOC);
		if (!path_array[i])
			return (free(cmd), ft_memfree(path_array), NULL);
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

void	*ft_pipex(char **argv, char **envp)
{
	char	**path;
	char 	**cmd;
	int		pipe_fd[2];
//	int		fd_input;

	path = ft_get_path(argv, envp);
	cmd = ft_get_cmd(argv[2]);
	if (pipe(pipe_fd) < 0)
		return (NULL);
	int	fd_in = open(argv[1], O_RDONLY);
	dup2(fd_in, STDIN_FILENO);
	int	pid = fork();
	close(pipe_fd[WRITE_TO]);
	if (pid == 0)
	{
		dup2(pipe_fd[WRITE_TO], STDOUT_FILENO);
		close(pipe_fd[READ_FROM]);
		ft_find_path(path, cmd, envp);
	}
	wait(NULL);
	ft_printf("ARGV + 1 : %s\n", argv + 1);
	path = ft_get_path(argv + 1, envp);
	cmd = ft_get_cmd(argv[4]);
	int	fd_out = open(argv[5], O_RDWR);
	dup2(fd_out, STDOUT_FILENO);
	dup2(pipe_fd[READ_FROM], STDIN_FILENO);
	ft_find_path(path, cmd, envp);
	return (NULL);
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;

	ft_pipex(argv, envp);
}
