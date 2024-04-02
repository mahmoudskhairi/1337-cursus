/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:14:25 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/02 23:19:17 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i++]);
    return (--i);
}

void send_char(char c, int pid)
{
    int i = 7;
    while (i >= 0)
    {
        if(((c >> i) & 1))
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


void    send_len(int pid, int c)
{
    int i = 31;
    while (i >= 0)
    {
        if(((c >> i) & 1))
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

int main(int ac, char **av)
{
    if (ac == 3)
    {
        int pid = atoi (av[1]);
        char *str = av[2];
        int i = 0;
        int len = ft_strlen(av[2]);
        send_len(pid, len);
        while (str[i])
        {
            send_char(str[i], pid);
            i++;
        }
    }
    else
        write (1, "\n", 1);
}
