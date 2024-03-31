/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:29:04 by mskhairi          #+#    #+#             */
/*   Updated: 2023/12/28 17:27:03 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long long	tot;
	long long	check;

	sign = 1;
	tot = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		check = tot;
		tot = (tot * 10) + (*str - 48);
		if (tot / 10 != check && sign == 1)
			return (-1);
		else if (tot / 10 != check && sign == -1)
			return (0);
		str++;
	}
	return (sign * tot);
}
