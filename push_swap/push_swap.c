/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:19:05 by csteylae          #+#    #+#             */
/*   Updated: 2024/02/22 21:35:02 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_if_sorted(t_stack **tail)
{
	t_stack	*tmp;

	tmp = (*tail)->next;
	while (tmp != *tail)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	ft_printf("stack is sorted !");
	return (1);
}

void	ft_apply_double_rotation(t_stack **cheapest_elem, t_stack **a, t_stack **b)
{
	if ((*cheapest_elem)->push_price > (*cheapest_elem)->target->push_price)
	{
		while ((*cheapest_elem)->target->index != 0)
			ft_rotate_both(a, b);
		while ((*cheapest_elem)->index != 0)
			ft_rotate(a, 'a');
		return;
	}
	else 
	{
		while ((*cheapest_elem)->index != 0)
			ft_rotate_both(a, b);
		while ((*cheapest_elem)->target->index != 0)
			ft_rotate(b, 'b');
	}
	return;
}

void	ft_apply_double_reverse_rotation(t_stack **cheapest_elem, t_stack **a, t_stack **b)
{
	if ((*cheapest_elem)->push_price < (*cheapest_elem)->target->push_price)
	{
		while ((*cheapest_elem)->target->index != 0)
			ft_reverse_rotate_both(a, b);
		while ((*cheapest_elem)->index != 0)
			ft_reverse_rotate(a, 'a');
		return;
	}
	else 
	{
		while ((*cheapest_elem)->index != 0)
			ft_reverse_rotate_both(a, b);
		while ((*cheapest_elem)->target->index != 0)
			ft_reverse_rotate(b, 'b');
	}
	return;
}

void	ft_apply_diverse_rotations(t_stack **cheapest_elem, t_stack **a, t_stack **b)
{
	if ((*cheapest_elem)->push_price >= 0 && (*cheapest_elem)->push_price <= 0)
	{
		while ((*cheapest_elem)->index != 0)
			ft_rotate(a, 'a');
		while ((*cheapest_elem)->target->index != 0)
				ft_reverse_rotate(b, 'b');
		return;
	}
	while ((*cheapest_elem)->index != 0)
		ft_reverse_rotate(a, 'a');
	while ((*cheapest_elem)->target->index != 0)
		ft_rotate(b, 'b');
	return;
}

void	ft_check_which_moves(t_stack **cheapest_nb, t_stack **stack_a, t_stack **stack_b)
{
	if ((*cheapest_nb)->push_price > 0 && (*cheapest_nb)->target->push_price > 0)
	{
		ft_apply_double_rotation(cheapest_nb, stack_a, stack_b);
		return;
	}
	if ((*cheapest_nb)->push_price < 0 && (*cheapest_nb)->target->push_price < 0)
	{
		ft_apply_double_reverse_rotation(cheapest_nb, stack_a, stack_b);
		return;
	}
	
	ft_apply_diverse_rotations(cheapest_nb, stack_a, stack_b);
}

void	ft_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *cheapest_elem;

	if (ft_check_if_sorted(stack_a))
			return;
	ft_push(stack_a, stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
	while ((*stack_a)) 
	{
		cheapest_elem = ft_find_the_cheapest_nb(stack_a, stack_b);
		ft_check_which_moves(&cheapest_elem, stack_a, stack_b);
		ft_push(stack_a, stack_b, 'b');
	}
	t_stack	*max_elem = ft_find_the_biggest((*stack_b));
	if (max_elem->push_price < 0)
	{
		while (max_elem->index != 0)
			ft_reverse_rotate(stack_b, 'b');
	}
	if (max_elem->index > 0)
	{
		while (max_elem->index != 0)
			ft_rotate(stack_b, 'b');
	}
	while ((*stack_b))
		ft_push(stack_a, stack_b, 'a');
}
