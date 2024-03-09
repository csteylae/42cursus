/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:37:23 by csteylae          #+#    #+#             */
/*   Updated: 2024/03/07 20:27:25 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_if_max_or_min_in_other_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*max;
	t_stack	*min;

	if (!stack_b)
		return (0);
	max = ft_find_the_biggest(stack_a);
	min = ft_find_the_smallest(stack_a);
	if (stack_b->content < stack_b->next->content)
	{
		if (stack_b->content < max->content || stack_b->content > min->content)
			return (1);
		if (stack_b->next->content < max->content 
			|| stack_b->next->content > min->content)
			return (1);
	}
	return (0);
}

void	ft_sort_three(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*mid;

	if (!stack_a || !*stack_a)
		return ;
	tmp = (*stack_a)->next;
	mid = tmp->next;
	if (mid->content > tmp->content && mid->content > (*stack_a)->content)
		ft_reverse_rotate(stack_a, 'a');
	else if (tmp->content > mid->content && tmp->content > (*stack_a)->content)
		ft_rotate(stack_a, 'a');
	if ((*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		if (ft_check_if_max_or_min_in_other_stack(*stack_a, *stack_b))
			ft_sswap(stack_a, stack_b);
		else
			ft_swap(stack_a, 'a');
	}
	return ;
}

void	ft_insert_at_its_place(t_stack **stack_a, t_stack *stack_b)
{
	t_stack	*head;

	if (!stack_a || !stack_b)
		return ;
	head = (*stack_a)->next;
	if ((*stack_a)->next->content > stack_b->next->content
		|| stack_b->next->content > (*stack_a)->content) 
		return ;
	if (stack_b->next->content < (*stack_a)->content && 
		stack_b->next->content > (*stack_a)->prev->content)
	{
		ft_reverse_rotate(stack_a, 'a');
		return ;
	}
	if (stack_b->next->content > (*stack_a)->next->content 
		&& stack_b->next->content < (*stack_a)->next->next->content)
	{
		ft_rotate(stack_a, 'a');
		return ;
	}
	ft_rotate(stack_a, 'a');
	while (stack_b->next->content > (*stack_a)->next->content && 
		head->content != (*stack_a)->next->content)
		ft_rotate(stack_a, 'a');
	return ;
}

void	ft_stackreorder(t_stack	**a)
{
	t_stack	*smallest_nb;

	if (!a || ! *a)
		return ;
	smallest_nb = ft_find_the_smallest(*a);
	if (smallest_nb->index > ((*a)->index / 2))
	{
		while (smallest_nb->index != 0)
			ft_reverse_rotate(a, 'a');
	}
	else
	{
		while (smallest_nb->index != 0)
			ft_rotate(a, 'a');
	}
}

void	ft_minisort(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int	nb;

	nb = argc - 1;
	if (ft_check_if_sorted(stack_a))
		return ;
	if (nb == 2 || (*stack_a)->index == 1)
	{
		if ((*stack_a)->content < (*stack_a)->next->content)
			ft_swap(stack_a, 'a');
	}
	else if (nb == 3)
		ft_sort_three(stack_a, stack_b);
	else
	{
		while ((*stack_a)->index != 2)
			ft_push(stack_a, stack_b, 'b');
		ft_sort_three(stack_a, stack_b);
		while ((*stack_b))
		{
			ft_insert_at_its_place(stack_a, *stack_b);
			ft_push(stack_a, stack_b, 'a');
			ft_stackreorder(stack_a);
		}
	}
	return ;
}
