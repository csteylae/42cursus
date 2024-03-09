/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:10:07 by csteylae          #+#    #+#             */
/*   Updated: 2024/02/29 18:39:10 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_shift_index_from_back(t_stack **tail)
{
	t_stack	*end;

	if (!*tail)
		return ;
	end = *tail;
	while (end != (*tail)->next)
	{
		end->index = end->prev->index;
		end = end->prev;
	}
	(*tail)->next->index = 0;
	return ;
}

void	ft_shift_index_from_front(t_stack **tail)
{
	t_stack	*tmp;

	if (!tail || !*tail)
		return ;
	tmp = (*tail)->next;
	while (tmp != *tail)
	{
		tmp->index = tmp->next->index;
		tmp = tmp->next;
	}
	(*tail)->index = (*tail)->prev->index + 1;
	return ;
}
