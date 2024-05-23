/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:14:25 by mskhairi          #+#    #+#             */
/*   Updated: 2024/05/23 12:22:42 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(90);
		i--;
	}
}

void	send_len(int pid, int c)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if (((c >> i) & 1))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		i--;
		usleep(90);
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;
	int		i;
	int		len;

	if (ac == 3 && ft_atoi(av[1]) >= 0)
	{
	    pid = ft_atoi(av[1]);
		str = av[2];
		i = 0;
		len = ft_strlen(str);
		if (len == 0)
		{
			ft_printf("\e[31;40mInvalid message (empty)\n");
			exit(1);
		}
		send_len(pid, len);
		i = 0;
		while (str[i])
			send_char(str[i++], pid);
	}
	else
        ft_printf("\e[31;40mSorry, Ivalid Number Of Arguments Or PID!!\e[0m");
}
