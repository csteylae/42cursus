/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:39:02 by csteylae          #+#    #+#             */
/*   Updated: 2023/12/12 15:43:08 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	ft_checktype(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '0' && str[i + 1])
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	*ft_lstfree(t_list **head)
{
	t_list	*tmp;

	while (*head != NULL)
	{
		tmp = *head;
		*head = tmp->next;
		free(tmp);
	}
	head = NULL;
	return (NULL);
}

void	*ft_puterror(t_list **ptr)
{
	if (ptr)
		ft_lstfree(ptr);
	ft_putstr_fd("Error\n", 1);
	exit(1);
	return (NULL);
}

int	ft_duplcheck(t_list *head)
{
	int		nb;
	t_list	*tmp;

	nb = 0;
	tmp = head;
	while (head != NULL)
	{
		nb = tmp->content;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			if (tmp->content == nb)
				return (0);
		}
		tmp = head;
		tmp = tmp->next;
		head = tmp;
	}
	return (1);
}

t_list	*ft_parse_input(int argc, char **argv)
{
	long	nb;
	t_list	*new;
	t_list	*stack_a;

	nb = 0;
	stack_a = NULL;
	if (argc < 2)
		return (ft_puterror(NULL));
	while (++argv && *argv)
	{
		if (!ft_checktype(*argv))
			return (ft_puterror(&stack_a));
		nb = ft_atol(*argv);
		if (nb > INT_MAX || nb < INT_MIN)
			return (ft_puterror(&stack_a));
		new = ft_lstnew(nb);
		if (!new)
			return (ft_puterror(&stack_a));
		ft_lstadd_back(&stack_a, new);
	}
	if (!ft_duplcheck(stack_a))
		return (ft_puterror(&stack_a));
	return (stack_a);
}
//
//void	ft_lstprint(t_list *head)
//{
//	int	i = 0;
//	t_list	*tmp;
//	
//	tmp = head;
//	while (tmp != NULL)
//	{
//		ft_printf("%i stack_a->content : %i\n", i, tmp->content);
//		i++;
//		tmp = tmp->next;
//	}
//}
//		
//int main(int argc, char **argv)
//{
//	t_list	*stack_a;
//
//	stack_a = ft_parse_input(argc, argv);
//	ft_lstprint(stack_a);
//	ft_lstfree(&stack_a);
//	system("leaks push_swap");
//	return (0);
//
//}
