/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_linked_list_fts.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:58:01 by csteylae          #+#    #+#             */
/*   Updated: 2024/02/22 19:46:15 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
  
#include "push_swap.h"

void	ft_update_stack_index_in_rotate_sens(t_stack **tail)
{
	t_stack	*end;
	if (!*tail)
		return;
	end = *tail;
	while (end != (*tail)->next)
	{
		end->index = end->prev->index;
		end = end->prev;
	}
	(*tail)->next->index = 0;
	return;
}

void	ft_add_new_index_in_reverse_rotate_sens(t_stack **tail)
{
	if (!tail || !*tail)
		return;
	t_stack	*tmp;

	tmp = (*tail)->next;
	while (tmp != *tail)
	{
		tmp->index = tmp->next->index;
		tmp = tmp->next;
	}
	(*tail)->index = (*tail)->prev->index + 1;
	return;
}	

t_stack	*ft_stacknew(int content)
{
	t_stack	*node;

	node = (t_stack*)malloc(sizeof(t_stack));
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
	t_stack 	*first;

	if (!tail || !new)
		return;
	if (*tail == NULL)
	{
		*tail = new;
		return;
	}
	first = (*tail)->next;
	new->next = first;
	new->prev = *tail;
	(*tail)->next = new;
	first->prev = new;
	*tail = new;
	(*tail)->index = (*tail)->prev->index + 1;
	return;
}

void	ft_stackadd_front(t_stack	**tail, t_stack *new)
{
	t_stack	*first;

	if (!tail || !new)
		return;
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
	ft_add_new_index_in_reverse_rotate_sens(tail);
	return ;
}

void	*ft_stackfree(t_stack	**tail)
{
	t_stack	*tmp;
	t_stack	*end;

	if (*tail)
	{
		tmp = *tail;
		end = tmp;
		tmp = tmp->next;
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

void	ft_stackprint(t_stack	*tail)
{
	t_stack	*tmp;
	if (!tail)
	{
		ft_printf("null\n");
		return;
	}
	tmp = tail->next;
	ft_printf("%ith : %i", tmp->index, tmp->content);
	ft_printf("\n");
	tmp = tmp->next;
	while (tmp != tail->next)
	{
		ft_printf("%ith : %i",tmp->index, tmp->content);
		ft_printf("\n");
		tmp = tmp->next;
	}
	return;
}
