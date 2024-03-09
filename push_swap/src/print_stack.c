/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_not_keep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:23:27 by csteylae          #+#    #+#             */
/*   Updated: 2024/02/29 19:24:30 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_stackprint(t_stack	*tail)
{
	t_stack	*tmp;

	if (!tail)
	{
		ft_printf("null\n");
		return ;
	}
	tmp = tail->next;
	ft_printf("%ith : %i", tmp->index, tmp->content);
	ft_printf("\n");
	tmp = tmp->next;
	while (tmp != tail->next)
	{
		ft_printf("%ith : %i", tmp->index, tmp->content);
		ft_printf("\n");
		tmp = tmp->next;
	}
	return ;
}

void	ft_show_result(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\n------STACK_A--------\n");
	ft_stackprint(stack_a);
	ft_printf("------STACK_B--------\n");
	ft_stackprint(stack_b);
	ft_printf("---------------------\n");
	return ;
}
