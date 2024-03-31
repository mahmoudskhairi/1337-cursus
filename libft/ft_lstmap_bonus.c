/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:02:23 by mskhairi          #+#    #+#             */
/*   Updated: 2024/01/06 15:47:56 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*ret;
	void	*d;

	head = NULL;
	if (lst && f && del)
	{
		while (lst)
		{
			d = f(lst->content);
			ret = ft_lstnew(d);
			if (!ret)
			{
				del(d);
				ft_lstclear(&head, del);
				return (NULL);
			}
			ft_lstadd_back(&head, ret);
			lst = lst->next;
		}
	}
	return (head);
}
