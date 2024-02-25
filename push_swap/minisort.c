/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:37:23 by csteylae          #+#    #+#             */
/*   Updated: 2024/02/17 15:59:11 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:00:04 by csteylae          #+#    #+#             */
/*   Updated: 2024/02/16 12:36:17 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack *middle;

	tmp = (*stack_a)->next;
	middle = tmp->next;
	if (middle->content > tmp->content && middle->content > middle->next->content)
	{
		ft_reverse_rotate(stack_a, 'a');
		if ((*stack_a)->next->content > (*stack_a)->next->next->content)
			ft_swap(stack_a, 'a');
	}
	if (tmp->content > middle->content && tmp->content > tmp->prev->content)
	{
		ft_rotate(stack_a, 'a');
		if ((*stack_a)->next->content > (*stack_a)->next->next->content)
			ft_swap(stack_a, 'a');
	}
	if (tmp->prev->content > tmp->content && middle->content < tmp->content)
		ft_swap(stack_a, 'a');
	return;
}

void	ft_minisort(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int	nb;

	nb = argc - 1;
	if (nb == 2)
	{
		if ((*stack_a)->next->content > (*stack_a)->content)
			ft_swap(stack_a, 'a');
	}
	if (nb == 3)
		ft_sort_three(stack_a);
	ft_show_result(*stack_a, *stack_b);
	ft_stackfree(stack_a);
	ft_stackfree(stack_b);
	return;
}
