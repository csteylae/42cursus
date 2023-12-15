/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_linked_list_fts.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:58:01 by csteylae          #+#    #+#             */
/*   Updated: 2023/12/13 15:45:38 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
  
#include "push_swap.h"

t_list	*ft_circlst_new(int content)
{
	t_list	*node;

	node = (t_list*)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = node;
	return (node);
}

void	ft_circlst_add_back(t_list	**tail, t_list *new)
{
	t_list	*tmp;

	tmp = *tail;
	if (!tail || !new)
		return ;
	if (*tail == NULL)
	{
		*tail = new;
		return ;
	}
	new->next = tmp->next;
	tmp->next = new;
	tmp = tmp->next;
	*tail = tmp;
}

void	ft_circlst_add_front(t_list	**tail, t_list *new)
{
	t_list	*tmp;

	tmp = *tail;
	if (!tail || !new)
		return;
	if (!*tail)
	{
		*tail = new;
		return ;
	}
	new->next = tmp->next;
	tmp->next = new;
	return ;
}

void	*ft_circlst_free(t_list	**tail)
{
	t_list	*tmp;
	t_list	*end;

	tmp = *tail;
	end = tmp;
	tmp = tmp->next;
	while (tmp != end)
	{
		*tail = tmp;
		tmp = tmp->next;
		free(*tail);
	}
	free(end);
	return (NULL);
}

void	ft_circlst_print(t_list	*tail)
{
	if (!tail)
	{
		ft_printf("null\n");
		return;
	}
	t_list	*tmp;

	tmp = tail->next;
	ft_printf("1st node :%i\n", tmp->content);
	tmp = tmp->next;
	while (tmp != tail->next)
	{
		ft_printf("printed node : %i\n", tmp->content);
		tmp = tmp->next;
	}
	return;
}
//
//int main(void)
//{
//	t_list	*tail;
//	t_list	*new;
//	int	i = 0;
//
//	tail = NULL;
//	new = NULL;
//	while (i < 3)
//	{
//		new = ft_circlst_new(i);
//		if (!new)
//		{
//			ft_circlst_free(&tail);
//			return (0);
//		}
//		ft_circlst_add_front(&tail, new);
//		i++;
//	}
//	ft_circlst_print(tail);
//	ft_circlst_free(&tail);
//	return (0);
//}
//	
//






