/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:05:20 by csteylae          #+#    #+#             */
/*   Updated: 2024/04/25 17:36:40 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_redirect_streams(int fd_in, int fd_out, t_pipex **pipex)
{
	if (dup2(fd_in, STDIN_FILENO) == -1)
		ft_puterror(NULL, "dup2.1 error\n", pipex);
	close(fd_in);
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		ft_puterror(NULL, "dup2.2 error\n", pipex);
	close(fd_out);
}

void	exec_cmd_in_child(t_pipex **ptr, int pipe_fd[2], int *fd_prev, int argc)
{
	int	first_cmd;

	first_cmd = argc - 3;
	if ((*ptr)->index == first_cmd)
	{
		close(pipe_fd[READ_FROM]);
		ft_redirect_streams(*fd_prev, pipe_fd[WRITE_TO], ptr);
	}
	else if ((*ptr)->index == LAST_CMD)
	{
		close(pipe_fd[WRITE_TO]);
		close(pipe_fd[READ_FROM]);
		ft_redirect_streams(*fd_prev, (*ptr)->fd_out, ptr);
	}
	else
	{
		close(pipe_fd[READ_FROM]);
		ft_redirect_streams(*fd_prev, pipe_fd[WRITE_TO], &(*ptr));
	}
	ft_find_path((*ptr)->path, (*ptr)->cmd, (*ptr)->envp);
	close(pipe_fd[READ_FROM]);
	close(pipe_fd[WRITE_TO]);
	close(*fd_prev);
	ft_puterror(NULL, "command not found\n", ptr);
}

void	ft_manage_pipe_in_parent(t_pipex **pipex, int pipe_fd[2], int *fd_prev)
{
	close(pipe_fd[WRITE_TO]);
	close(*fd_prev);
	*fd_prev = pipe_fd[READ_FROM];
	(*pipex)->index--;
}

void	ft_wait_children(int nb_of_child)
{
	int	i;

	i = 0;
	while (i < nb_of_child)
	{
		wait(NULL);
		i++;
	}
}

void	ft_pipeline(const int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	pid_t	pid;
	int		pipe_fd[2];
	int		fd_prev;
	int		i;

	ft_init(&pipex, argc, argv, envp);
	fd_prev = pipex->fd_in;
	i = 0;
	while (pipex->index != 0)
	{
		if (pipe(pipe_fd) < 0)
			ft_puterror(NULL, "pipe error\n", &pipex);
		pid = fork();
		if (pid < 0)
			ft_puterror(NULL, "fork error\n", &pipex);
		else if (pid == 0)
			exec_cmd_in_child(&pipex, pipe_fd, &fd_prev, argc);
		ft_manage_pipe_in_parent(&pipex, pipe_fd, &fd_prev);
		i++;
		ft_init_pipex(&pipex, argv[2 + i], envp);
	}
	close(fd_prev);
	ft_free_struct(&pipex);
	ft_wait_children(i);
}
