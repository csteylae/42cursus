/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:52:03 by csteylae          #+#    #+#             */
/*   Updated: 2024/04/16 11:38:20 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_set_init_value(t_pipex **pipex)
{
	*pipex = malloc(sizeof(**pipex) * 1);
	if (!*pipex)
		ft_puterror(NULL, "Malloc failed\n", NULL);
	(*pipex)->path = NULL;
	(*pipex)->cmd = NULL;
	(*pipex)->envp = NULL;
	(*pipex)->fd_in = -1;
	(*pipex)->fd_out = -1;
}

void	ft_init_pipex(t_pipex **pipex, char *argv, char **envp)
{
	if (!*pipex)
		ft_set_init_value(pipex);
	if (!*pipex)
		ft_puterror(NULL, "Malloc failed\n", NULL);
	if ((*pipex)->cmd)
		ft_memfree((*pipex)->cmd);
	if ((*pipex)->path)
		ft_memfree((*pipex)->path);
	(*pipex)->envp = envp;
	(*pipex)->cmd = ft_get_cmd(argv);
	if (!(*pipex)->cmd)
		ft_puterror(NULL, "Malloc failed\n", NULL);
	(*pipex)->path = ft_get_path((*pipex)->cmd[0], envp);
	if (!(*pipex)->path)
		ft_puterror(NULL, "Malloc failed\n", pipex);
}

void	ft_open_files(t_pipex **pipex, char **argv, int argc)
{
	char	*infile;
	char	*outfile;

	infile = argv[1];
	outfile = argv[argc - 1];
	if (access(infile,F_OK ) < 0)
		ft_puterror(infile, "No such file or directory\n", pipex);
	if (access(infile, R_OK) < 0)
		ft_puterror(infile, "Permission denied\n", pipex);
	(*pipex)->fd_in = open(infile, O_RDONLY);
	if ((*pipex)->fd_in < 0)
		ft_puterror(infile, "Error. Can not open file\n", pipex);
	(*pipex)->fd_out = open(outfile, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if ((*pipex)->fd_out < 0)
		ft_puterror(outfile, "Error. Can not open file\n", pipex);
}
