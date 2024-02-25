/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:39:02 by csteylae          #+#    #+#             */
/*   Updated: 2024/02/22 19:09:41 by csteylae         ###   ########.fr       */
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
	if (ptr)
		ft_stackfree(ptr);
	ft_putstr_fd("Error\n", 1);
	exit(1);
	return (NULL);
}

int	ft_duplcheck(t_stack *tail)
{
	int	nb;
	t_stack	*tmp;
	t_stack *end;

	tmp = tail->next;
	end = tail;
	tail = tail->next;
	while (tmp != end)
	{
		nb = tmp->content;
		while(tmp != end)
		{
			tmp = tmp->next;
			if (tmp->content == nb)
				return(0);
		}
		tail = tail->next;
		tmp = tail;
	}
	return (1);
}

t_stack	*ft_parse_input(int argc, char **argv)
{
	long	nb;
	t_stack	*new;
	t_stack	*stack_a;

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
		new = ft_stacknew(nb);
		if (!new)
			return (ft_puterror(&stack_a));
		ft_stackadd_back(&stack_a, new);
	}
	if (!ft_duplcheck(stack_a))
		return (ft_puterror(&stack_a));
	return (stack_a);
}

void	ft_show_result(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\n------STACK_A--------\n");
	ft_stackprint(stack_a);
	ft_printf("------STACK_B--------\n");
	ft_stackprint(stack_b);
	ft_printf("---------------------\n");
	return;
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_parse_input(argc, argv);
	stack_b = NULL;
	ft_push_swap(&stack_a, &stack_b);
//	ft_show_result(stack_a, stack_b);
//	ft_rotate_both(&stack_a, &stack_b);
//	ft_show_result(stack_a, stack_b);
//
//	if (!stack_a)
//		exit(0);
//	if (argc < 5)
//	{
//		ft_minisort(&stack_a, &stack_b, argc);
//		return (0);
//	}
//	ft_show_result(stack_a, stack_b);
////	ft_push_swap(&stack_a, &stack_b);
//	ft_stackfree(&stack_a);
//	ft_stackfree(&stack_b);
////	system("leaks push_swap");
	return (0);
}
