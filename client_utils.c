/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:46:27 by welyousf          #+#    #+#             */
/*   Updated: 2024/05/06 13:10:06 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

extern int	g_len;

int	ft_atoi(const char *str)
{
	int					i;
	long long			sign;
	unsigned long long	result;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == '+')
	{
		sign = !(str[i] == '-') - (str[i] == '-');
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = 10 * result + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

void	send_char(unsigned char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
}
