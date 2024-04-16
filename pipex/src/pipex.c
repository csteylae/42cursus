/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:05:20 by csteylae          #+#    #+#             */
/*   Updated: 2024/04/16 11:38:23 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_find_path(char **path, char **cmd, char **envp)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (access(path[i], X_OK) == 0)
			execve(path[i], cmd, envp);
		else
		i++;
	}
	ft_printf("error cmd not found\n");
}

void	ft_redirect_streams(int fd_in, int fd_out, t_pipex **pipex)
{
	if (dup2(fd_in, STDIN_FILENO) == -1)
		ft_puterror(NULL, "dup2 error\n", pipex);
	close(fd_in);
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		ft_puterror(NULL, "dup2 error\n", pipex);
	close(fd_out);
}

void	ft_exec_cmd(t_pipex *pipex)
{
	ft_find_path(pipex->path, pipex->cmd, pipex->envp);
	ft_puterror(NULL, "Error. Can not execute execve()\n", &pipex);
}

/*
void	ft_pipeline(int argc, char **argv, char **envp)
{
	t_pipex *pipex;
	int		pipe_fd[2];
	int		new_pipe[2];
	pid_t	*pid_array;

	pipex = NULL;
	pid_array = malloc(sizeof(*pid_array) * (argc - 3));
	if (!pid_array)
		ft_puterror(NULL, "Malloc failed\n", NULL);
	ft_init_pipex(&pipex, argv[2], envp);
	ft_open_files(&pipex, argv, argc);
	pipex->len = argc - (3 + 1);;
	pipe(pipe_fd);

	while (pipex->len != 0)
	{

		pipex->len--;
*/

void	*ft_pipex(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	pid_t	pid1;
	pid_t	pid2;	
	int		pipe_fd[2];
	int		status;

	pipex = NULL;
	ft_init_pipex(&pipex, argv[2], envp);
	ft_open_files(&pipex, argv, argc);
	pipe(pipe_fd);
	pid1 = fork();
	if (pid1 == 0)
	{
		close(pipe_fd[READ_FROM]);
		ft_redirect_streams(pipex->fd_in, pipe_fd[WRITE_TO], &pipex);
		ft_exec_cmd(pipex);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		close(pipe_fd[WRITE_TO]);
		ft_init_pipex(&pipex, argv[3], envp);
		ft_redirect_streams(pipe_fd[READ_FROM], pipex->fd_out, &pipex);
		ft_exec_cmd(pipex);
	}
	close(pipe_fd[READ_FROM]);
	close(pipe_fd[WRITE_TO]);
	while(wait(&status) > 0);
	return(NULL);
}

int main(int argc, char **argv, char **envp)
{
	ft_verify_envp(envp);
	if (argc != 5)
		return (1);
	ft_pipex(argc, argv, envp);
}
