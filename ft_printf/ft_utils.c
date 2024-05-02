/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:41:08 by welyousf          #+#    #+#             */
/*   Updated: 2023/12/30 15:48:02 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd_a(char c, int *i)
{
	write(1, &c, 1);
	(*i)++;
	return (*i);
}

int	ft_putchar_fd(char c, int fd)
{
	int	x;

	x = write(fd, &c, 1);
	return (x);
}

int	ft_putnbr_fd(int n, int *trucker)
{
	long	x;

	x = n;
	if (x < 0)
	{
		x = -x;
		ft_putchar_fd_a('-', trucker);
	}
	if (x >= 10)
	{
		ft_putnbr_fd(x / 10, trucker);
	}
	ft_putchar_fd_a((x % 10) + 48, trucker);
	return (*trucker);
}
