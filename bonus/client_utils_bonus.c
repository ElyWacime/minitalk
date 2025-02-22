/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:46:27 by welyousf          #+#    #+#             */
/*   Updated: 2024/05/06 13:02:55 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

void	handel_sig1(int *num)
{
	(void)num;
	ft_printf("1");
}

void	handel_sig2(int *num)
{
	(void)num;
	ft_printf("0");
	return ;
}

void	func(int sig, siginfo_t *info, void *ptr)
{
	(void)info;
	(void)ptr;
	if (sig == SIGUSR1)
	{
		ft_printf("Messege send succesfuly!\n");
		exit(1);
	}
}
