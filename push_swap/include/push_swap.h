/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:34:00 by csteylae          #+#    #+#             */
/*   Updated: 2024/03/06 13:14:50 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*prev;
	struct s_stack	*next;
	int				index;
	struct s_stack	*target;
	int				push_price;
}	t_stack;
char	**ft_split_argv(char *argv, char c);
char	**ft_check_which_input(int *argc, char **argv);
void	ft_check_for_leak(char ***argv, int *argc);
void	*ft_free_the_split(char **argv);
int		ft_checktype(char *str);
void	*ft_puterror(t_stack **ptr);
int		ft_duplcheck(t_stack *tail);
t_stack	*ft_parse_input(int argc, char **argv, t_stack *stack_a);
int		main(int argc, char **argv);
t_stack	*ft_stacknew(int content);
void	ft_stackadd_back(t_stack **tail, t_stack *new);
void	ft_stackadd_front(t_stack **tail, t_stack *new);
void	*ft_stackfree(t_stack	**tail);
void	ft_shift_index_from_front(t_stack **tail);
void	ft_shift_index_from_back(t_stack **tail);
void	ft_rotate(t_stack **tail, unsigned char c);
void	ft_rotate_both(t_stack **a, t_stack **b);
void	ft_reverse_rotate(t_stack **tail, unsigned char c);
void	ft_reverse_rotate_both(t_stack **a, t_stack **b);
void	ft_swap(t_stack **tail, unsigned char c);
void	ft_sswap(t_stack **stack_a, t_stack **stack_b); 
void	ft_push(t_stack **stack_a, t_stack **stack_b, unsigned char c);
int		ft_check_if_max_or_min_in_other_stack(t_stack *stack_a,
			t_stack *stack_b);
void	ft_sort_three(t_stack **stack_a, t_stack **stack_b);	
void	ft_insert_at_its_place(t_stack **stack_a, t_stack *stack_b);
void	ft_stackreorder(t_stack	**a);
void	ft_minisort(t_stack **stack_a, t_stack **stack_b, int argc);
int		ft_check_if_sorted(t_stack **tail);
void	ft_push_swap(t_stack **a, t_stack **b);
void	ft_apply_rotate_both(t_stack **elem, t_stack **a, t_stack **b);
void	ft_apply_reverse_rotate_both(t_stack **elem, t_stack **a, t_stack **b);
void	ft_apply_diverse_rotations(t_stack **elem, t_stack **a, t_stack **b);
void	ft_check_which_moves(t_stack **elem, t_stack **a, t_stack **b);
t_stack	*ft_find_the_biggest(t_stack *stack_b);
t_stack	*ft_find_the_smallest(t_stack *stack_b);
void	ft_assign_target(t_stack **elem, t_stack *stack_b);
void	ft_assign_push_price_from_index(t_stack **stack);
int		ft_calculate_final_push_price(t_stack **elem);
void	ft_set_target(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_find_the_cheapest_nb(t_stack **stack_a, t_stack **stack_b);
void	ft_stackprint(t_stack *tail); //do not keep
void	ft_show_result(t_stack *stack_a, t_stack *stack_b);//do not keep
#endif
