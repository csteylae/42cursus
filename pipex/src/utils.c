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

void	*ft_puterror(char *argv, char *msg, t_pipex **ptr)
{
	if (argv)
		ft_printf("%s :", argv);
	ft_putstr_fd(msg, STDERR_FILENO);
	if (ptr && *ptr && (*ptr)->path)
		ft_memfree((*ptr)->path);
	if (ptr && *ptr && (*ptr)->cmd)
		ft_memfree((*ptr)->cmd);
	if (ptr && *ptr)
		free(*ptr);
	exit(EXIT_FAILURE);
	return (NULL);
}

int	ft_is_equal(char *s1, char *s2)
{
	if (!ft_strncmp(s1, s2, ft_strlen(s1)))
			return (1);
	return (0);
}

void	ft_print_struct(t_pipex	*pipex)
{
	int	i;

	i = 0;
	while (pipex->path[i])
	{
		ft_printf("%s\n", pipex->path[i]);
		i++;
	}
	i = 0;
	while (pipex->cmd[i])
	{
		ft_printf("%s\n", pipex->cmd[i]);
		i++;
	}
	ft_printf("%d\n %d\n", pipex->fd_in, pipex->fd_out);
}
