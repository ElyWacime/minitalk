/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:46:40 by welyousf          #+#    #+#             */
/*   Updated: 2023/12/30 15:46:42 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(fd, s, len);
	return (ft_strlen(s));
}

int	ft_puthexa_fd(size_t x, int *trucker)
{
	char	*str;

	str = "0123456789abcdef";
	if (x >= 16)
	{
		ft_puthexa_fd(x / 16, trucker);
	}
	ft_putchar_fd_a(str[x % 16], trucker);
	return (*trucker);
}
