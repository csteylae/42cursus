/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_push_price.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:25:01 by csteylae          #+#    #+#             */
/*   Updated: 2024/02/29 19:15:31 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_assign_push_price_from_index(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack)->next->next;
	(*stack)->next->push_price = (*stack)->next->index;
	while (tmp != (*stack)->next)
	{
		if (tmp->index <= ((*stack)->index / 2))
			tmp->push_price = tmp->index;
		if (tmp->index > ((*stack)->index / 2))
			tmp->push_price = - (((*stack)->index + 1) - tmp->index);
		tmp = tmp->next;
	}
}

int	ft_calculate_final_push_price(t_stack **tmp)
{
	int	cost;
	int	target_cost;

	cost = (*tmp)->push_price;
	target_cost = (*tmp)->target->push_price;
	cost = (*tmp)->push_price;
	if (cost >= 0 && target_cost >= 0)
	{
		if (cost > target_cost)
			return (cost);
		else 
			return (target_cost);
	}
	if (cost <= 0 && target_cost <= 0)
	{
		if (cost < target_cost)
			return (-cost);
		else 
			return (-target_cost);
	}
	if (cost < 0)
		cost = -cost;
	else if (target_cost < 0)
		target_cost = -target_cost;
	return (target_cost + cost);
}

void	ft_set_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	ft_assign_target(&(*stack_a)->next, *stack_b);
	tmp = (*stack_a)->next->next;
	while (tmp != (*stack_a)->next)
	{
		ft_assign_target(&tmp, *stack_b);
		tmp = tmp->next;
	}
}

t_stack	*ft_find_the_cheapest_nb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		min;
	int		count;
	t_stack	*cheapest_nb;

	ft_set_target(stack_a, stack_b);
	ft_assign_push_price_from_index(stack_a);
	ft_assign_push_price_from_index(stack_b);
	tmp = (*stack_a)->next->next;
	count = ft_calculate_final_push_price(&(*stack_a)->next);
	min = count;
	cheapest_nb = (*stack_a)->next;
	while (tmp != (*stack_a)->next)
	{
		count = ft_calculate_final_push_price(&tmp);
		if (count < min)
		{
			min = count;
			cheapest_nb = tmp;
		}
		tmp = tmp->next;
	}
	return (cheapest_nb);
}
