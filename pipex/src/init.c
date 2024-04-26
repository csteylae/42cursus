/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:52:03 by csteylae          #+#    #+#             */
/*   Updated: 2024/04/25 16:06:36 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	ft_verify_envp(char **envp, char *argv)
{
	int	i;

	i = 0;
	if (!envp && ft_strchr(argv, '/') == NULL)
		return (0);
	while (envp[i] && !ft_is_equal(PATH, envp[i]))
		i++;
	if ((!envp[i] || !ft_strlen(envp[i])) && ft_strchr(argv, '/') == 0)
		return (0);
	return (1);
}

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
	if (!ft_verify_envp(envp, argv))
		ft_puterror(NULL, "environ not found\n", pipex);
	if (!argv[0])
		ft_puterror(NULL, "parse error \n", pipex);
	if ((*pipex)->cmd)
		ft_memfree((*pipex)->cmd);
	if ((*pipex)->path)
		ft_memfree((*pipex)->path);
	(*pipex)->envp = envp;
	(*pipex)->cmd = ft_get_cmd(argv);
	if (!(*pipex)->cmd)
		ft_puterror(NULL, "Malloc failed\n", pipex);
	(*pipex)->path = ft_get_path((*pipex)->cmd[0], envp);
	if (!(*pipex)->path)
		ft_puterror(NULL, "error\n", pipex);
}

void	ft_open_files(t_pipex **pipex, char **argv, int argc)
{
	char	*infile;
	char	*outfile;

	infile = argv[1];
	outfile = argv[argc - 1];
	(*pipex)->fd_out = open(outfile, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if ((*pipex)->fd_out < 0)
		ft_puterror(outfile, "Error. Can not open file\n", pipex);
	if (access(infile, F_OK) < 0)
		ft_puterror(infile, "no such file or directory\n", pipex);
	if (access(infile, R_OK) < 0)
		ft_puterror(infile, "permission denied\n", pipex);
	(*pipex)->fd_in = open(infile, O_RDONLY);
	if ((*pipex)->fd_in < 0)
		ft_puterror(infile, "Error. Can not open file\n", pipex);
}

void	ft_init(t_pipex **pipex, int argc, char **argv, char **envp)
{
	int	first_cmd;

	first_cmd = argc - 3;
	*pipex = NULL;
	ft_set_init_value(pipex);
	ft_open_files(pipex, argv, argc);
	ft_init_pipex(pipex, argv[2], envp);
	(*pipex)->index = first_cmd;
}
