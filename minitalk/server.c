// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   server.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/04/02 23:08:37 by mskhairi          #+#    #+#             */
// /*   Updated: 2024/04/06 14:38:46 by mskhairi         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "minitalk.h"

t_list  info;

void ft_init()
{
    info.c = 0;
    info.count = 7;
    info.i = 0;
    info.len_bits = 31;
    info.check_alloc = -1;
    info.len = 0;
    info.client_pid = 0;
}

void ft_alloc(int signal)
{
    if(signal == SIGUSR1)
        info.c |= (1 << info.count);
    info.count--;
    if (info.count < 0)
    {
        info.string[info.i++] = (char)info.c;
        if(ft_strlen(info.string) == info.len)
        {
            write(1, info.string, ft_strlen(info.string));
            write(1, "\n", 1);
            ft_free (&info.string);
            info.i = 0;
            info.len_bits = 31;
            info.check_alloc = -1;
        }
        info.count = 7;
        info.c = 0;
    }
}

void handle_len(int signal)
{
    static int c;
    static int count = 31;

    if (info.check_alloc == -1)
    {
        info.string = ft_calloc(info.len + 1, 1);
        if (!info.string)
            exit(1);
        info.check_alloc = 0;
    }
    if(signal == SIGUSR1)
        info.len |= (1 << count);
    count--;
    if (count < 0)
    {   
        count = 31;
        c = 0;
    }
}


void handle(int signal, siginfo_t *frs, void *ntg)
{
    (void)ntg;
    info.client_pid = frs->si_pid;
    if (info.client_pid != info.new_pid)
    {
        info.count = 7;
        info.c = 0;
        info.new_pid = info.client_pid;
        info.len_bits = 31;
        ft_free(&info.string);
        info.check_alloc = -1;
        info.i = 0;
        info.len = 0;
    }
    if (info.len_bits >= 0)
    {
        handle_len(signal);
        info.len_bits--;
    }
    else
    {
        ft_alloc(signal);
    }
}

int main()
{
    struct sigaction sa;
    
    ft_init();
    sa.sa_sigaction = handle;
    sa.sa_flags = SA_SIGINFO;
    ft_printf("i am a server\n");
    ft_printf("my pid is : %d\n", getpid());
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
    {
        pause ();
    }
}


