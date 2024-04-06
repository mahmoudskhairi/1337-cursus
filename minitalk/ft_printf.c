/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:25:50 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/06 13:49:15 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static	int ft_putnbr(int n)
{
	long	nbr;
	int		count;

	count = 0;
	nbr = n;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr < 10)
	{
		count += ft_putchar(nbr + 48);
	}
	else
	{
		count += ft_putnbr(nbr / 10);
		count += ft_putchar(nbr % 10 + 48);
	}
	return (count);
}

static	int ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		count += ft_putstr("(null)");
		return (count);
	}
	while (*s)
	{
		count += ft_putchar(*s++);
	}
	return (count);
}

static int	ft_format(char c, va_list pa)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(pa, int));
	else if (c == 's')
		count += ft_putstr(va_arg(pa, char *));
	else
		count += ft_putchar(c);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '\0')
				return (count);
			count += ft_format(s[++i], args);
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}