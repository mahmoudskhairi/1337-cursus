/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:40:15 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/06 18:15:21 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>



typedef struct init {
    int c;
    int count;
    int i;
    int len;
    int len_bits;
    int check_alloc;
    char *string;
    int client_pid;
    int new_pid;
} t_list;

int	ft_printf(const char *s, ...);
void	*ft_calloc(size_t count, size_t size);
int ft_strlen(char *str);
void ft_free(char **s);

#endif