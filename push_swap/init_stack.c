/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:39:02 by csteylae          #+#    #+#             */
/*   Updated: 2023/12/13 16:02:11 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	ft_checktype(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '0' && str[i + 1])
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	*ft_puterror(t_list **ptr)
{
	if (ptr)
		ft_circlst_free(ptr);
	ft_putstr_fd("Error\n", 1);
	exit(1);
	return (NULL);
}

int	ft_duplcheck(t_list *tail)
{
	int		nb;
	t_list	*tmp;
	t_list	*end;

	end = tail;
	tmp = NULL;
	tail = tail->next;
	while (tail != end)
	{
		tmp = tail;
		nb = tmp->content;
		while (tmp != end)
		{
			tmp = tmp->next;
			if (tmp->content == nb)
				return (0);
		}
		tail = tail->next;
	}
	return (1);
}

t_list	*ft_parse_input(int argc, char **argv)
{
	long	nb;
	t_list	*new;
	t_list	*stack_a;

	nb = 0;
	stack_a = NULL;
	if (argc < 2)
		return(NULL);
	while (++argv && *argv)
	{
		if (!ft_checktype(*argv))
			return (ft_puterror(&stack_a));
		nb = ft_atol(*argv);
		if (nb > INT_MAX || nb < INT_MIN)
			return (ft_puterror(&stack_a));
		new = ft_circlst_new(nb);
		if (!new)
			return (ft_puterror(&stack_a));
		ft_circlst_add_back(&stack_a, new);
	}
	if (!ft_duplcheck(stack_a))
		return (ft_puterror(&stack_a));
	return (stack_a);
}

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = ft_parse_input(argc, argv);
	if (!stack_a)
		exit(0);
	stack_b = NULL;
	ft_push(&stack_a, &stack_b, 'b');
	ft_push(&stack_a, &stack_b, 'b');
	ft_push(&stack_a, &stack_b, 'b');
	ft_printf("stack_a :\n");
	ft_circlst_print(stack_a);
	ft_printf("stack_b :\n");
	ft_circlst_print(stack_b);

////	system("leaks push_swap");
	return (0);
}
