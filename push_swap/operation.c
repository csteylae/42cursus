/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:37:22 by csteylae          #+#    #+#             */
/*   Updated: 2024/02/22 18:58:09 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update_stacks(t_stack **tail, t_stack **new_stack)
{
	t_stack	*tmp;

	if (!tail || !*tail)
		return;
	if (*tail == (*tail)->next)
	{
		ft_stackadd_front(new_stack, *tail);
		*tail = NULL;
		return;
	}
	tmp = (*tail)->next;
	(*tail)->next = tmp->next;
	tmp->next->prev = *tail;
	tmp->next = tmp;
	tmp->prev = tmp;
	tmp->index = 0;
	tmp->target = NULL;
	ft_stackadd_front(new_stack, tmp);
	ft_update_stack_index_in_rotate_sens(tail);
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
	return;
}

void	ft_swap(t_stack **tail, unsigned char c)
{
	int	nb;

	if (!tail || !*tail || *tail == (*tail)->next)
		return;
	nb = (*tail)->next->next->content;
	(*tail)->next->next->content = (*tail)->next->content;
	(*tail)->next->content = nb;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

void	ft_sswap(t_stack	**stack_a, t_stack **stack_b)
{
	ft_swap(stack_a, 'o');
	ft_swap(stack_b, 'o');
	ft_printf("ss");
}

void	ft_rotate(t_stack **tail, unsigned char c)
{
	if (!tail || !*tail)
		return;
	*tail = (*tail)->next;
	ft_update_stack_index_in_rotate_sens(tail);
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
	else
		return;
}

void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a, 'o');
	ft_rotate(stack_b, 'o');
	ft_printf("rr\n");
}

void	ft_reverse_rotate(t_stack **tail, unsigned char c)
{
	if (!tail || !*tail )
		return;
	*tail = (*tail)->prev;
	ft_add_new_index_in_reverse_rotate_sens(tail);
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}
void	ft_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a, 'o');
	ft_reverse_rotate(stack_b, 'o');
	ft_printf("rrr\n");
}
