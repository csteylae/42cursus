/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:34:00 by csteylae          #+#    #+#             */
/*   Updated: 2023/12/13 12:52:59 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

t_list	*ft_circlst_new(int content);
void	ft_circlst_add_back(t_list **tail, t_list *new);
void	ft_circlst_add_front(t_list **tail, t_list *new);
void	*ft_circlst_free(t_list	**tail);
void	ft_circlst_print(t_list *tail); //do not keep
void	ft_rotate(t_list **tail, unsigned char c);
void	ft_swap(t_list *tail, unsigned char c);
void	ft_sswap(t_list *stack_a, t_list *stack_b); 
void	ft_push(t_list **stack_a, t_list **stack_b, unsigned char c);

#endif
