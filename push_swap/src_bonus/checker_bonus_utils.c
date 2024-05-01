/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:24:02 by mskhairi          #+#    #+#             */
/*   Updated: 2024/05/01 11:21:51 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_node;
	t_list	*tmp;

	first_node = *stack_b;
	tmp = *stack_b;
	if (!first_node)
		return ;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, first_node);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_node;

	first_node = *stack_a;
	if (!first_node)
		return ;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, first_node);
}

void	swap(t_list **stack)
{
	t_list	*tmp1;

	if (ft_lstsize(*stack) >= 2)
	{
		tmp1 = *stack;
		*stack = (*stack)->next;
		tmp1->next = (*stack)->next;
		(*stack)->next = tmp1;
	}
}

void	rotate(t_list **stack)
{
	t_list	*first_node;
	t_list	*last_node;

	if (ft_lstsize(*stack) >= 2)
	{
		first_node = *stack;
		*stack = (*stack)->next;
		last_node = ft_lstlast(*stack);
		last_node->next = first_node;
		first_node->next = NULL;
	}
}

void	reverce_rotate(t_list **stack)
{
	t_list	*first_node;
	t_list	*prev_node;
	t_list	*last_node;

	if (ft_lstsize(*stack) >= 2)
	{
		first_node = *stack;
		prev_node = ft_lstprev(*stack);
		last_node = ft_lstlast(*stack);
		*stack = last_node;
		last_node->next = first_node;
		prev_node->next = NULL;
	}
}
