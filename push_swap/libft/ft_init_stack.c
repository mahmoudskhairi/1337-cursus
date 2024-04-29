/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 08:59:16 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/28 09:29:18 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_stack(char **str, t_list **stack_a)
{
	t_list	*new_node;
	int		i;

	i = 0;
	while (str[i])
	{
		new_node = ft_lstnew(ft_atoi(str[i]));
		if (!new_node)
			break ;
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
}
