/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:54:19 by mskhairi          #+#    #+#             */
/*   Updated: 2023/12/29 11:29:07 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		join_len;

	if (!s1 || !s2)
		return (NULL);
	join_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(join_len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (*s1)
	{
		*str++ = *s1++;
	}
	while (*s2)
	{
		*str++ = *s2++;
	}
	*str = '\0';
	return (str - join_len);
}
