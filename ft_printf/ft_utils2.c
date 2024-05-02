/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:46:32 by welyousf          #+#    #+#             */
/*   Updated: 2023/12/30 15:46:34 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	tohexa(unsigned long long x)
{
	int	count;
	int	trucker;

	trucker = 0;
	count = write(1, "0x", 2);
	count += ft_puthexa_fd(x, &trucker);
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n, int *trucker)
{
	if (n >= 10)
		ft_putnbr_fd(n / 10, trucker);
	ft_putchar_fd_a((n % 10) + 48, trucker);
	return (*trucker);
}

int	ft_puthexa_x(unsigned int x, int *trucker, char a)
{
	t_var	var;

	var.str = "0123456789abcdef";
	var.str2 = "0123456789ABCDEF";
	if (a == 'x')
	{
		if (x >= 16)
			ft_puthexa_x(x / 16, trucker, a);
		ft_putchar_fd_a(var.str[x % 16], trucker);
	}
	else if (a == 'X')
	{
		if (x >= 16)
			ft_puthexa_x(x / 16, trucker, a);
		ft_putchar_fd_a(var.str2[x % 16], trucker);
	}
	return (*trucker);
}

int	tohexa_x(unsigned int a, char x)
{
	int	count;
	int	trucker;

	trucker = 0;
	count = 0;
	count += ft_puthexa_x(a, &trucker, x);
	return (count);
}
