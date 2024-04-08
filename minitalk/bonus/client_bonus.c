/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:09:56 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/08 09:05:28 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minitalk_bonus.h"

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

void	handle(int signal)
{
	if (signal == SIGUSR1)
		write(1, "\e[32;40mthe string is received succussfully , thanks !!!",
			56);
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

	if (ac == 3 && ft_atoi(av[1]) > 2)
	{
		pid = ft_atoi(av[1]);
		str = av[2];
		i = 0;
		len = ft_strlen(av[2]);
		if (len == 0)
		{
            ft_printf("\e[31;40mInvalid message (empty)\n");
			exit(1);
		}
		signal(SIGUSR1, handle);
		send_len(pid, len);
		i = 0;
		while (str[i])
			send_char(str[i++], pid);
	}
	else
		ft_printf("\e[31;40mSorry, Ivalid Number Of Arguments Or PID!!\e[0m");
}
