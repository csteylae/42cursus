/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:19:05 by csteylae          #+#    #+#             */
/*   Updated: 2024/03/07 20:27:44 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_if_sorted(t_stack **tail)
{
	t_stack	*tmp;

	tmp = (*tail)->next;
	while (tmp->content != (*tail)->content)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_apply_the_final_rotation(t_stack **stack_b)
{
	t_stack	*max_elem;

	max_elem = ft_find_the_biggest(*stack_b);
	if (max_elem->index > (*stack_b)->index / 2)
	{
		while (max_elem->index != 0)
			ft_reverse_rotate(stack_b, 'b');
	}
	if (max_elem->index <= (*stack_b)->index / 2)
	{
		while (max_elem->index != 0)
			ft_rotate(stack_b, 'b');
	}
}

void	ft_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*elem;

	if (ft_check_if_sorted(stack_a))
		return ;
	ft_push(stack_a, stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
	while (*stack_a) 
	{
		elem = ft_find_the_cheapest_nb(stack_a, stack_b);
		ft_check_which_moves(&elem, stack_a, stack_b);
		ft_push(stack_a, stack_b, 'b');
	}
	ft_apply_the_final_rotation(stack_b);
	while (*stack_b)
		ft_push(stack_a, stack_b, 'a');
}
