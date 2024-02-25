/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:39:12 by csteylae          #+#    #+#             */
/*   Updated: 2024/02/22 21:35:01 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_the_biggest(t_stack *stack_b)
{
	t_stack	*tmp;
	t_stack	*max_target;
	int	max;

	tmp = stack_b->next->next;
	max_target = stack_b->next;
	max = stack_b->next->content;
	while (tmp != stack_b->next)
	{
		if (max < tmp->content)
		{
			max = tmp->content;
			max_target = tmp;
		}
		tmp = tmp->next;
	}
	return (max_target);

}

t_stack	*ft_find_the_smallest(t_stack *stack_b)
{
	t_stack	*tmp;
	t_stack	*min_target;
	int	min;

	tmp = stack_b->next->next;
	min_target = stack_b->next;
	min = stack_b->next->content;
	while (tmp != stack_b->next)
	{
		if (min > tmp->content)
		{
			min = tmp->content;
			min_target = tmp;
		}
		tmp = tmp->next;
	}
	return (min_target);
}


void	ft_assign_target(t_stack **elem, t_stack *stack_b)
{
	t_stack	*tmp;
	t_stack	*max_target;
	t_stack *min_target;
			
	tmp = stack_b->next->next;
	max_target = ft_find_the_biggest(stack_b);
	min_target = ft_find_the_smallest(stack_b);
	if ((*elem)->content > max_target->content)
	{
		(*elem)->target = max_target;
		return;
	}
	if ((*elem)->content < min_target->content)
	{
		(*elem)->target = max_target;
		return;
	}
	while (tmp != stack_b->next)
	{
		if ((*elem)->content > tmp->content && tmp->content > min_target->content)
			min_target = tmp;
		tmp = tmp->next;
	}
	(*elem)->target = min_target;
}

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

int	ft_calculate_final_push_price(t_stack *tmp)
{
	int	cost;
	int	target_cost;

	cost = tmp->push_price;
	target_cost = tmp->target->push_price;
	cost = tmp->push_price;
	if (cost > 0 && target_cost > 0)
	{
		if (cost > target_cost)
			return (cost);
		else 
			return (target_cost);
	}
	if (cost < 0 && target_cost < 0)
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

t_stack	*ft_find_the_cheapest_nb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int count;
	int	min;
	t_stack	*cheapest_nb;

	ft_assign_target(&(*stack_a)->next, *stack_b);
	tmp = (*stack_a)->next->next;
	while (tmp != (*stack_a)->next)
	{
		ft_assign_target(&tmp, *stack_b);
		tmp = tmp->next;
	}
	ft_assign_push_price_from_index(stack_a);
	ft_assign_push_price_from_index(stack_b);
	tmp = (*stack_a)->next->next;
	count = ft_calculate_final_push_price((*stack_a)->next);
	min = count;
	cheapest_nb = (*stack_a)->next;
	while (tmp != (*stack_a)->next)
	{
		if (count < min)
		{
			min = count + 1;
			cheapest_nb = tmp;
		}
		count = ft_calculate_final_push_price(tmp);
		tmp = tmp->next;
	}
	return (cheapest_nb);
}
