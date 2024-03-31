/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:14:25 by mskhairi          #+#    #+#             */
/*   Updated: 2024/03/30 19:47:37 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>


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
        usleep(500);
        i--;
    }
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        int pid = atoi (av[1]);
        char *str = av[2];
        int i = 0;
        while (str[i])
        {
            send_char(str[i], pid);
            i++;
        }
        send_char('\n', pid);
        // send_len(atoi(av[3]));
        // send_char('A', pid);
        //    kill(pid, SIGUSR1);
        printf("the signal is sent");
    }
    else
        write (1, "\n", 1);
}
