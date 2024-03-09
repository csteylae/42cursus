/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:47:30 by csteylae          #+#    #+#             */
/*   Updated: 2024/02/29 18:38:45 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*node;

	node = (t_stack *) malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->prev = node;
	node->next = node;
	node->index = 0;
	node->target = NULL;
	return (node);
}

void	ft_stackadd_back(t_stack **tail, t_stack *new)
{
	t_stack	*first;

	if (!tail || !new)
		return ;
	if (*tail == NULL)
	{
		*tail = new;
		return ;
	}
	first = (*tail)->next;
	new->next = first;
	new->prev = *tail;
	(*tail)->next = new;
	first->prev = new;
	*tail = new;
	(*tail)->index = (*tail)->prev->index + 1;
	return ;
}

void	ft_stackadd_front(t_stack	**tail, t_stack *new)
{
	t_stack	*first;

	if (!tail || !new)
		return ;
	if (!*tail)
	{
		*tail = new;
		return ;
	}
	first = (*tail)->next;
	new->next = first;
	new->prev = *tail;
	(*tail)->next = new;
	first->prev = new;
	ft_shift_index_from_front(tail);
	return ;
}

void	*ft_stackfree(t_stack	**tail)
{
	t_stack	*tmp;
	t_stack	*end;

	if (*tail)
	{
		end = *tail;
		tmp = (*tail)->next;
		if (*tail != (*tail)->next)
		{
			while (tmp != end)
			{
				*tail = tmp;
				tmp = tmp->next;
				free(*tail);
				*tail = NULL;
			}
			free(tmp);
			tmp = NULL;
			return (NULL);
		}
		free(*tail);
		*tail = NULL;
	}
	return (NULL);
}
