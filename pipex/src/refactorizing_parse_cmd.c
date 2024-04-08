/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:04:25 by csteylae          #+#    #+#             */
/*   Updated: 2024/04/08 16:36:44 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

t_pipex	*ft_init_pipex(t_pipex *pipex, char *argv, char **envp)
{
	if (pipex)
	{
		ft_memfree(pipex->path);
		ft_memfree(pipex->cmd);
	}
	if (!pipex)
		pipex = malloc(sizeof(*pipex) * 1);
	if (!pipex)
		ft_puterror(NULL, "Malloc failed\n", NULL);
	if (!envp || !*envp)	
		return (ft_puterror(NULL, "Error. Envp does not exist\n", NULL));
	pipex->envp = envp;
	pipex->cmd = ft_get_cmd(argv);
	if (!pipex->cmd)
		return(ft_puterror(NULL, "Malloc failed\n", NULL));
	pipex->path = ft_get_path(pipex->cmd[0], envp);
	if (!pipex->path)
		return (ft_puterror(NULL, "Malloc failed\n", &pipex));
	return (pipex);
}

void	ft_open_files(t_pipex *pipex, char **argv, int argc)
{
	char	*infile;
	char	*outfile;

	infile = argv[1];
	outfile = argv[argc - 1];
	if (access(infile,F_OK ) < 0)
		ft_puterror(infile, "No such file or directory\n", &pipex);
	if (access(infile, R_OK) < 0)
		ft_puterror(infile, "Permission denied\n", &pipex);
	pipex->fd_in = open(infile, O_RDONLY);
	if (pipex->fd_in < 0)
		ft_puterror(infile, "Error. Can not open file\n", &pipex);
	pipex->fd_out = open(outfile, O_RDWR | O_CREAT);
	if (pipex->fd_out < 0)
		ft_puterror(outfile, "Error. Can not open file\n", &pipex);
}

void	*ft_pipex(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int	pipe_fd[2];
	pipex = NULL;
	int	pid;

	if (pipe(pipe_fd) < 0)
		ft_puterror(NULL, "Can not create a pipe\n", NULL);
	pipex = ft_init_pipex(pipex, argv[2], envp);
	ft_open_files(pipex, argv, argc);
	dup2(pipex->fd_in, STDIN_FILENO);
	close(pipex->fd_in);
	pid = fork();
	if (pid == 0)
	{
		dup2(pipe_fd[WRITE_TO], STDOUT_FILENO);
		close(pipe_fd[READ_FROM]);
		ft_find_path(pipex->path, pipex->cmd, pipex->envp);
		ft_puterror(NULL, "Error. Can not execute execve()\n", &pipex);
	}
	close(pipe_fd[WRITE_TO]);
	pipex = ft_init_pipex(pipex, argv[argc - 2], envp);
	dup2(pipe_fd[READ_FROM], STDIN_FILENO);
	close(pipe_fd[READ_FROM]);
	dup2(pipex->fd_out, STDOUT_FILENO);
	close(pipex->fd_out);
	ft_find_path(pipex->path, pipex->cmd, pipex->envp);
	return (NULL);
}

int main(int argc, char **argv, char **envp)
{
	ft_pipex(argc, argv, envp);
}
