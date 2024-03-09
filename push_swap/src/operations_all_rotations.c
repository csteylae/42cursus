/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_all_rotations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:42:03 by csteylae          #+#    #+#             */
/*   Updated: 2024/02/29 18:37:49 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotate(t_stack **tail, unsigned char c)
{
	if (!tail || !*tail)
		return ;
	*tail = (*tail)->next;
	ft_shift_index_from_back(tail);
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
	else
		return ;
}

void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a, 'o');
	ft_rotate(stack_b, 'o');
	ft_printf("rr\n");
}

void	ft_reverse_rotate(t_stack **tail, unsigned char c)
{
	if (!tail || !*tail)
		return ;
	*tail = (*tail)->prev;
	ft_shift_index_from_front(tail);
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
