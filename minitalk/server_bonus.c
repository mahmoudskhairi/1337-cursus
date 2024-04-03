/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:07:56 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/03 00:50:00 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"


int len = -1;

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

void handle_len(int signal, int *len)
{
    static int c;
    static int count = 31;

    if(signal == SIGUSR1)
        c |= (1 << count);
    count--;
    if (count < 0)
    {
        *len = c; 
        count = 31;
        c = 0;
    }
}


void handle(int signal, siginfo_t *frs, void *ntg)
{
    static int c;
    static int count = 7;
    static char *string;
    static int i;
    static int client_pid;
    static int new_pid;
    static int len_bits = 31;
    static int check_alloc = -1;
    (void)ntg;

    client_pid = frs->si_pid;
    if (client_pid != new_pid)
    {
        count = 7;
        c = 0;
        new_pid = client_pid;
        len_bits = 31;
        free(string);
        string = NULL;
        check_alloc = -1;
        i = 0;
    }
    if (len_bits >= 0)
    {
        handle_len(signal, &len);
        len_bits--;
    }
    else
    {
        if (check_alloc == -1)
        {
            string = malloc(len + 1);
            string[len] = 0;
            check_alloc = 0;
        }
        if(signal == SIGUSR1)
            c |= (1 << count);
        count--;
        if (count < 0)
        {
            string[i] = (char)c;
            i++;
            if(ft_strlen(string) == len)
            {
                write(1, string, ft_strlen(string));
                write(1, "\n", 1);
                kill(client_pid, SIGUSR1);
                free(string);
                string = NULL;
                i = 0;
                len_bits = 31;
                check_alloc = -1;
            }
            count = 7;
            c = 0;
        }
    }
}

int main()
{
    struct sigaction sa;
    sa.sa_sigaction = handle;
    sa.sa_flags = SA_SIGINFO;
    printf("i am a bonus_server\n");
    printf("my pid is : %d\n", getpid());
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
    {
        pause ();
    }
}