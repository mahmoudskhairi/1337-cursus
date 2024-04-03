/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:14:25 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/02 23:38:47 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		;
	return (--i);
}

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

	if (ac == 3)
	{
		pid = atoi(av[1]);
		str = av[2];
		i = 0;
		len = ft_strlen(av[2]);
		send_len(pid, len);
		while (str[i])
		{
			send_char(str[i], pid);
			i++;
		}
	}
	else
		write(1, "\n", 1);
}
