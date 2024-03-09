/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:06:36 by csteylae          #+#    #+#             */
/*   Updated: 2024/03/05 17:58:49 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
		return (0);
	stack_a = ft_parse_input(argc, argv, stack_a);
	if (!stack_a)
		return (0);
	if (argc < 7 && stack_a->index <= 4)
	{
		ft_minisort(&stack_a, &stack_b, argc);
		ft_stackfree(&stack_b);
		ft_stackfree(&stack_a);
		exit(EXIT_SUCCESS);
	}
	ft_push_swap(&stack_a, &stack_b);
	ft_stackfree(&stack_a);
	ft_stackfree(&stack_b);
	exit(EXIT_SUCCESS);
}
