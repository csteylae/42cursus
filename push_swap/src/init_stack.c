/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:39:02 by csteylae          #+#    #+#             */
/*   Updated: 2024/03/07 20:43:53 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_checktype(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' && !str[i + 1])
		return (0);
	if (str[i] == '-')
	{
		i++;
		if (str[i] == '0')
			return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	*ft_puterror(t_stack **ptr)
{
	if (*ptr)
		ft_stackfree(ptr);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	*ft_free_the_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	while (i >= 0)
	{
		free(argv[i]);
		i--;
	}
	free(argv);
	return (NULL);
}

int	ft_duplcheck(t_stack *tail)
{
	int		nb;
	t_stack	*tmp;
	t_stack	*end;

	if (!tail)
		return (0);
	tmp = tail->next;
	end = tail;
	tail = tail->next;
	while (tail != end)
	{
		nb = tmp->content;
		while (tmp != end)
		{
			tmp = tmp->next;
			if (tmp->content == nb)
				return (0);
		}
		tail = tail->next;
		tmp = tail;
	}
	return (1);
}

t_stack	*ft_parse_input(int argc, char **argv, t_stack *stack_a)
{
	long	nb;
	t_stack	*new;
	char	**ptr;

	argv = ft_check_which_input(&argc, argv);
	ptr = argv;
	if (!argv)
		return (NULL);
	while (argv && *argv)
	{
		if (!ft_checktype(*argv))
			return (ft_check_for_leak(&ptr, &argc), ft_puterror(&stack_a));
		nb = ft_atol(*argv);
		if (nb > 2147483647 || nb < -2147483648 || (nb == 0 && *argv[0] != '0'))
			return (ft_check_for_leak(&ptr, &argc), ft_puterror(&stack_a));
		new = ft_stacknew(nb);
		if (!new)
			return (ft_check_for_leak(&ptr, &argc), ft_puterror(&stack_a));
		ft_stackadd_back(&stack_a, new);
		argv++;
	}
	ft_check_for_leak(&ptr, &argc);
	if (!ft_duplcheck(stack_a))
		return (ft_puterror(&stack_a));
	return (stack_a);
}
