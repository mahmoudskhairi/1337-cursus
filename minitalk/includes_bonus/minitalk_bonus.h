/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:40:09 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/08 08:51:33 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../utils/utils.h"
# include <signal.h>
# include <stdio.h> 
# include <stdlib.h>
# include <unistd.h>

typedef struct init
{
	int		c;
	int		count;
	int		i;
	int		len;
	int		len_bits;
	int		check_alloc;
	char	*string;
	int		client_pid;
	int		new_pid;
}			t_list;

#endif