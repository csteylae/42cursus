/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:43:25 by csteylae          #+#    #+#             */
/*   Updated: 2024/02/29 19:15:50 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_find_the_biggest(t_stack *stack_b)
{
	t_stack	*tmp;
	t_stack	*b_max;
	int		max;

	tmp = stack_b->next->next;
	b_max = stack_b->next;
	max = stack_b->next->content;
	while (tmp != stack_b->next)
	{
		if (max < tmp->content)
		{
			max = tmp->content;
			b_max = tmp;
		}
		tmp = tmp->next;
	}
	return (b_max);
}

t_stack	*ft_find_the_smallest(t_stack *stack_b)
{
	t_stack	*tmp;
	t_stack	*b_min;
	int		min;

	tmp = stack_b->next->next;
	b_min = stack_b->next;
	min = stack_b->next->content;
	while (tmp != stack_b->next)
	{
		if (min > tmp->content)
		{
			min = tmp->content;
			b_min = tmp;
		}
		tmp = tmp->next;
	}
	return (b_min);
}

void	ft_assign_target(t_stack **elem, t_stack *stack_b)
{
	t_stack	*tmp;
	t_stack	*b_max;
	t_stack	*b_min;

	tmp = stack_b->next->next;
	b_max = ft_find_the_biggest(stack_b);
	b_min = ft_find_the_smallest(stack_b);
	if ((*elem)->content > b_max->content || (*elem)->content < b_min->content)
	{
		(*elem)->target = b_max;
		return ;
	}
	if (stack_b->next->content < (*elem)->content)
		b_min = stack_b->next;
	while (tmp != stack_b->next)
	{
		if ((*elem)->content > tmp->content && tmp->content > b_min->content)
			b_min = tmp;
		tmp = tmp->next;
	}
	(*elem)->target = b_min;
}
