/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:29:04 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/28 13:16:41 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_error(char *str, int sign, long tot)
{
	if (*str || (sign * tot) < INT32_MIN || (sign * tot) > INT32_MAX)
		ft_print_error();
}

int	ft_atoi(char *str)
{
	int			sign;
	long long	tot;

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
	if (!*str)
		ft_print_error();
	while (*str >= '0' && *str <= '9')
	{
		tot = (tot * 10) + (*str - 48);
		str++;
	}
	ft_check_error(str, sign, tot);
	return (sign * tot);
}
