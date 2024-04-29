/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:50:42 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/29 16:46:22 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_duplcate_nbrs(t_list **stack)
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = *stack;
	if (ft_lstsize(*stack) < 2)
		exit(0);
	while (ptr1)
	{
		ptr2 = ptr1->next;
		while (ptr2)
		{
			if (ptr1->content == ptr2->content)
				ft_print_error();
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

void	ft_push_swap(t_list **stack_a, t_list **stack_b)
{
	int	range;

	if (ft_lstsize(*stack_a) == 2)
	{
		sa(stack_a);
		exit(0);
	}
	if (ft_lstsize(*stack_a) == 3)
	{
		ft_sort_three(stack_a);
		exit(0);
	}
	else if (ft_lstsize(*stack_a) == 5)
	{
		ft_sort_five(stack_a, stack_b);
		exit(0);
	}
	if (ft_lstsize(*stack_a) <= 100)
		range = 15; 
	else
		range = (8 * ft_lstsize(*stack_a)) / 100;
	ft_sort_stack(stack_a, stack_b, range);
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**argms;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	argms = NULL;
	(void)stack_b;
	if (ac >= 2)
	{
		while (av[i])
		{
			argms = ft_split(av[i], ' ');
			ft_init_stack(argms, &stack_a);
			ft_free_split(argms);
			i++;
		}
		ft_duplcate_nbrs(&stack_a);
		ft_indexing(&stack_a);
		if (ft_is_sorted(&stack_a))
			exit(0);
		ft_push_swap(&stack_a, &stack_b);
        ft_print_stack(stack_a, stack_b);
	}
}
