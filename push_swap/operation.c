/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:37:22 by csteylae          #+#    #+#             */
/*   Updated: 2023/12/13 16:02:08 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list	*tail, unsigned char c)
{
	t_list	*a;
	t_list	*b;

	a = tail->next;
	b = a->next;
	tail->next = b;
	a->next = b->next;
	b->next = a;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
	else 
		return;
}

void	ft_sswap(t_list	*stack_a, t_list *stack_b)
{
	ft_swap(stack_a, 'o');
	ft_swap(stack_b, 'o');
	ft_printf("ss");
}

void	ft_push(t_list	**stack_a, t_list **stack_b, unsigned char c)
{
	t_list	*first_node;
	t_list	*tail;

	if (c == 'b')
		tail = *stack_a;
	else 
		tail = *stack_b;
	if (!tail)
		return;
	first_node = tail->next;
	tail->next = first_node->next;
	first_node->next = first_node; //reinitialize the new link of the node thqt will be pushed on the other stack need to be linked to itself at the begining 
	if (tail == tail->next && c == 'b')
		*stack_a = NULL;
	else if (tail == tail->next && c == 'a')
		*stack_b = NULL;
	if (c == 'b')
	{
		ft_circlst_add_front(stack_b, first_node);
		ft_printf("pb\n");
		return;
	}
	ft_circlst_add_front(stack_a, first_node);
	ft_printf("pa\n");
}

void	ft_rotate(t_list **tail, unsigned char c)
{
	t_list	*tmp;

	tmp = *tail;
	*tail = tmp->next;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
	else
		return;
}

void	ft_rrotate(t_list *stack_a, t_list *stack_b)
{
	ft_rotate(&stack_a, 'o');
	ft_rotate(&stack_b, 'o');
	ft_printf("rr\n");
}


//int main(void)
//{
//	t_list	*new;
//	t_list	*tail = NULL;
//	int	i = 0;
//	while (i < 3)
//	{
//		new = ft_circlst_new(i);
//		ft_circlst_add_back(&tail, new);
//		i++;
//	}
//	ft_circlst_print(tail);
//	ft_rotate(&tail, 'a');
//	ft_circlst_print(tail);
//	return(0);
//}
