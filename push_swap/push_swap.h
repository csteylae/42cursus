/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:34:00 by csteylae          #+#    #+#             */
/*   Updated: 2024/02/22 18:20:27 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct	s_stack	*prev;
	struct	s_stack	*next;
	int				index;
	struct	s_stack	*target;
	int				push_price;
}	t_stack;

//file stack_functions.c
t_stack	*ft_stacknew(int content);
void	ft_stackadd_back(t_stack **tail, t_stack *new);
void	ft_stackadd_front(t_stack **tail, t_stack *new);
void	*ft_stackfree(t_stack	**tail);
void	ft_stackprint(t_stack *tail); //do not keep
void	ft_reverseprint(t_stack *tail);//do not keep
void	ft_show_result(t_stack *stack_a, t_stack *stack_b);//do not keep

//file operations.c
void	ft_rotate(t_stack **tail, unsigned char c);
void	ft_swap(t_stack **tail, unsigned char c);
void	ft_sswap(t_stack **stack_a, t_stack **stack_b); 
void	ft_push(t_stack **stack_a, t_stack **stack_b, unsigned char c);
void	ft_update_stack_index_in_rotate_sens(t_stack **tail);
void	ft_add_new_index_in_reverse_rotate_sens(t_stack **tail);
void	ft_rotate(t_stack **tail, unsigned char c);
void	ft_rotate_both(t_stack **a, t_stack **b);
void	ft_reverse_rotate(t_stack **tail, unsigned char c);
void	ft_reverse_rotate_both(t_stack **a, t_stack **b);
void	ft_push(t_stack **stack_a, t_stack **stack_b, unsigned char c);

//file minisort.c
void	ft_minisort(t_stack **stack_a, t_stack **stack_b, int argc);

//file push_swap.c
int		ft_check_if_sorted(t_stack **tail);
void	ft_apply_double_rotation(t_stack **cheapest_elem, t_stack **a, t_stack **b);
void	ft_apply_double_reverse_rotation(t_stack **cheapest_elem, t_stack **a, t_stack **b);
void	ft_apply_diverse_rotations(t_stack **cheapest_elem, t_stack **a, t_stack **b);
void	ft_check_which_moves(t_stack **cheapest_nb, t_stack **stack_a, t_stack **stack_b);
void	ft_push_swap(t_stack **a, t_stack **stack_b);

//file push_swap_utils.c : 
t_stack	*ft_find_the_biggest(t_stack *stack_b);
int		ft_is_the_smallest(t_stack *stack_a_elem, t_stack *stack_b);
void	ft_assign_target(t_stack **elem, t_stack *stack_b);
void	ft_assign_push_price_from_index(t_stack **stack);
int		ft_calculate_final_push_price(t_stack *elem);
t_stack	*ft_find_the_cheapest_nb(t_stack **stack_a, t_stack **stack_b);


#endif
