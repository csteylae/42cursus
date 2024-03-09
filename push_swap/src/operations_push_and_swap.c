/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push_and_swap.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:42:42 by csteylae          #+#    #+#             */
/*   Updated: 2024/02/29 18:38:17 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_update_stacks(t_stack **tail, t_stack **new_stack)
{
	t_stack	*tmp;

	if (!tail || !*tail)
		return ;
	if (*tail == (*tail)->next)
	{
		ft_stackadd_front(new_stack, *tail);
		*tail = NULL;
		return ;
	}
	tmp = (*tail)->next;
	(*tail)->next = tmp->next;
	tmp->next->prev = *tail;
	tmp->next = tmp;
	tmp->prev = tmp;
	tmp->index = 0;
	tmp->target = NULL;
	ft_stackadd_front(new_stack, tmp);
	ft_shift_index_from_back(tail);
}

void	ft_push(t_stack **stack_a, t_stack **stack_b, unsigned char c)
{
	if (c == 'b' && *stack_a) 
	{
		ft_update_stacks(stack_a, stack_b);
		ft_printf("pb\n");
	}
	if (c == 'a' && *stack_b)
	{
		ft_update_stacks(stack_b, stack_a);
		ft_printf("pa\n");
	}
	return ;
}

void	ft_swap(t_stack **tail, unsigned char c)
{
	int	nb;

	if (!tail || !*tail || *tail == (*tail)->next)
		return ;
	nb = (*tail)->next->next->content;
	(*tail)->next->next->content = (*tail)->next->content;
	(*tail)->next->content = nb;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

void	ft_sswap(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a, 'o');
	ft_swap(stack_b, 'o');
	ft_printf("ss\n");
}
