/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:42:25 by mskhairi          #+#    #+#             */
/*   Updated: 2023/12/16 17:11:37 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;

	len_needle = ft_strlen(needle);
	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack && len >= len_needle && len--)
	{
		if (ft_strncmp(haystack, needle, len_needle) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
