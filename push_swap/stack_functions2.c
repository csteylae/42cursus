/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:31:00 by csteylae          #+#    #+#             */
/*   Updated: 2024/02/17 15:42:00 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update_stack_index(t_stack **tail)
{
	t_stack	*tmp;

	tmp = (*tail)->next;
	tmp->index = 0;
	tmp = tmp->next;
	while (tmp != *tail)
	{
		tmp->index = tmp->index + 1;
		tmp = tmp->next;
	}
	(*tail)->index = tmp->index + 1;
	return;
}
