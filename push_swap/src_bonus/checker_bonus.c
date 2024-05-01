/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 08:27:49 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/30 16:30:50 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker_bonus.h"

void	ft_duplcate_nbrs(t_list **stack)
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = *stack;
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

void	check_r_rr(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strcmp(str, "ss\n"))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (!ft_strcmp(str, "ra\n"))
		rotate(stack_a);
	else if (!ft_strcmp(str, "rb\n"))
		rotate(stack_b);
	else if (!ft_strcmp(str, "rr\n"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (!ft_strcmp(str, "rra\n"))
		reverce_rotate(stack_a);
	else if (!ft_strcmp(str, "rrb\n"))
		reverce_rotate(stack_b);
	else if (!ft_strcmp(str, "rrr\n"))
	{
		reverce_rotate(stack_a);
		reverce_rotate(stack_b);
	}
	else
		ft_print_error();
}

void	ft_commands(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strcmp(str, "pa\n"))
	{
		push_a(stack_a, stack_b);
		return ;
	}
	else if (!ft_strcmp(str, "pb\n"))
	{
		push_b(stack_a, stack_b);
		return ;
	}
	else if (!ft_strcmp(str, "sa\n"))
	{
		swap(stack_a);
		return ;
	}
	else if (!ft_strcmp(str, "sb\n"))
	{
		swap(stack_b);
		return ;
	}
	check_r_rr(stack_a, stack_b, str);
}

void	ft_read_input(t_list **stack_a, t_list **stack_b)
{
	char	*str;

	str = 0;
	while (1)
	{
		str = get_next_line(0);
		if (!str)
		{
			if (ft_is_sorted(stack_a) && !ft_lstsize(*stack_b))
				ft_putendl_fd("OK", 1);
			else
				ft_putendl_fd("KO", 1);
			exit(0);
		}
		if (str[0] == '\n')
			ft_print_error();
		ft_commands(stack_a, stack_b, str);
		ft_free(&str);
	}
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**argms;
	int		i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	argms = NULL;
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
		ft_read_input(&stack_a, &stack_b);
	}
}
