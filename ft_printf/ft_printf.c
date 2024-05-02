/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:40:45 by welyousf          #+#    #+#             */
/*   Updated: 2023/12/30 15:40:57 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type(const char c, va_list lst)
{
	t_var	var;

	var.count = 0;
	var.trucker = 0;
	if (c == 'c')
		var.count += ft_putchar_fd(va_arg(lst, int), 1);
	else if (c == 'p')
		var.count += tohexa(va_arg(lst, unsigned long));
	else if (c == 's')
		var.count += ft_putstr_fd(va_arg(lst, char *), 1);
	else if (c == 'd')
		var.count += ft_putnbr_fd(va_arg(lst, int), &var.trucker);
	else if (c == 'i')
		var.count += ft_putnbr_fd(va_arg(lst, unsigned int), &var.trucker);
	else if (c == 'u')
		var.count += ft_putnbr_unsigned(va_arg(lst, unsigned int),
				&var.trucker);
	else if (c == 'x' || c == 'X')
		var.count += tohexa_x(va_arg(lst, unsigned int), c);
	else if (c == '%')
		var.count += write(1, "%", 1);
	else
		var.count += write(1, &c, 1);
	return (var.count);
}

int	ft_printf(const char *str, ...)
{
	t_var	var;
	va_list	lst;

	var.varint = write(1, "", 0);
	if (var.varint == -1)
		return (-1);
	var.count = 0;
	va_start(lst, str);
	if (*str == '%' && !(*(str + 1)))
		return (var.count);
	while (*str)
	{
		if (*str == '%')
		{
			var.count += print_type(*(++str), lst);
			str++;
		}
		else
		{
			var.count += write(1, str, 1);
			++str;
		}
	}
	va_end(lst);
	return (var.count);
}
