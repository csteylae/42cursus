/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:10:25 by csteylae          #+#    #+#             */
/*   Updated: 2024/03/04 13:21:41 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**ft_split_argv(char *argv, char c)
{
	char	**dst;

	dst = ft_split(argv, c);
	if (!dst)
		return (NULL);
	return (dst);
}

char	**ft_check_which_input(int *argc, char **argv)
{
	if (*argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (NULL);
		*argc = -1;
	}
	else
		argv++;
	return (argv);
}

void	ft_check_for_leak(char ***argv, int *argc)
{
	if (*argc == -1)
		ft_free_the_split(*argv);
}
