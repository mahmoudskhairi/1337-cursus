/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 07:28:01 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/08 08:52:29 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h> 
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int			ft_printf(const char *s, ...);
void		*ft_calloc(size_t count, size_t size);
int			ft_strlen(char *str);
void		ft_free(char **s);
int			ft_atoi(const char *str);

#endif