/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 09:40:56 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/28 12:29:46 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_sorted(t_list **stack)
{
	t_list	*tmp;
	int		num;
	int		next;

	tmp = *stack;
	if (ft_lstsize(tmp) < 2)
		exit(0);
	while (tmp && ft_lstsize(tmp) >= 2)
	{
		num = tmp->index;
		next = tmp->next->index;
		if (num > next)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
