/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:07:06 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/08 07:31:41 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*s;
	void			*p;
	size_t			bytes;

	bytes = count * size;
	if (size && bytes / size != count)
		return (NULL);
	p = malloc(bytes);
	if (p == NULL)
		return (NULL);
	s = p;
	while (bytes--)
	{
		*(unsigned char *)s++ = 0;
	}
	return (p);
}
