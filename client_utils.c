/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:46:27 by welyousf          #+#    #+#             */
/*   Updated: 2024/05/04 14:46:46 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	f(int x)
{
	if (x ==  SIGUSR1)
	{
		ft_printf("SIGUSR1\n");
	}
	else
	{
		ft_printf("SIGUSR2\n");
	}
}

void    send_char(unsigned char  c, int pid)
{
    int i;

    i = 0;
    while (i < 8)
    {
        if ((c >> i) & 1)
        {
            kill(pid, SIGUSR1);
            usleep(150);
			while (1)
			{
				if (signal(SIGUSR1, f))
					break;
				sleep(1);
			}
        }
        else
        {
            kill(pid, SIGUSR2);
            usleep(150);
			while (1)
			{
				if (signal(SIGUSR2, f))
					break;
				sleep(1);
			}
        }
        i++;
    }
}
