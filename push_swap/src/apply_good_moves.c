/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_good_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:52:49 by csteylae          #+#    #+#             */
/*   Updated: 2024/02/29 18:36:34 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_apply_rotate_both(t_stack **elem, t_stack **a, t_stack **b)
{
	if ((*elem)->push_price > (*elem)->target->push_price)
	{
		while ((*elem)->target->index != 0)
			ft_rotate_both(a, b);
		while ((*elem)->index != 0)
			ft_rotate(a, 'a');
		return ;
	}
	else 
	{
		while ((*elem)->index != 0)
			ft_rotate_both(a, b);
		while ((*elem)->target->index != 0)
			ft_rotate(b, 'b');
	}
	return ;
}

void	ft_apply_reverse_rotate_both(t_stack **elem, t_stack **a, t_stack **b)
{
	if ((*elem)->push_price < (*elem)->target->push_price)
	{
		while ((*elem)->target->index != 0)
			ft_reverse_rotate_both(a, b);
		while ((*elem)->index != 0)
			ft_reverse_rotate(a, 'a');
		return ;
	}
	else 
	{
		while ((*elem)->index != 0)
			ft_reverse_rotate_both(a, b);
		while ((*elem)->target->index != 0)
			ft_reverse_rotate(b, 'b');
	}
	return ;
}

void	ft_apply_diverse_rotations(t_stack **elem, t_stack **a, t_stack **b)
{
	if ((*elem)->push_price >= 0 && (*elem)->target->push_price <= 0)
	{
		while ((*elem)->index != 0)
			ft_rotate(a, 'a');
		while ((*elem)->target->index != 0)
			ft_reverse_rotate(b, 'b');
		return ;
	}
	while ((*elem)->index != 0)
		ft_reverse_rotate(a, 'a');
	while ((*elem)->target->index != 0)
		ft_rotate(b, 'b');
	return ;
}

void	ft_check_which_moves(t_stack **elem, t_stack **a, t_stack **b)
{
	if ((*elem)->push_price >= 0 && (*elem)->target->push_price >= 0)
	{
		ft_apply_rotate_both(elem, a, b);
		return ;
	}
	if ((*elem)->push_price <= 0 && (*elem)->target->push_price <= 0)
	{
		ft_apply_reverse_rotate_both(elem, a, b);
		return ;
	}
	ft_apply_diverse_rotations(elem, a, b);
}
