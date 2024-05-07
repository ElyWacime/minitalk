/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:42:14 by welyousf          #+#    #+#             */
/*   Updated: 2024/05/07 13:14:00 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handel_sig1(int *c, int *pow, int cl_pid)
{
	int	i;
	int	num;

	num = 1;
	i = 1;
	if (*pow > 0 && *pow < 8)
		power(&i, pow, &num, c);
	else if (*pow == 0)
	{
		*c += 1;
		*pow += 1;
	}
	if (*pow == 8)
	{
		if (*c == '\0')
			kill(cl_pid, SIGUSR1);
		else
		{
			write(1, (char *)c, 1);
			*pow = 0;
			*c = 0;
		}
	}
}

void	handel_sig2(int *c, int *pow, int cl_pid)
{
	*pow += 1;
	if (*pow == 8)
	{
		if (*c == '\0')
			kill(cl_pid, SIGUSR1);
		else
		{
			write(1, (char *)c, 1);
			*pow = 0;
			*c = 0;
		}
	}
}

void	reset_in_casse_failure(int *c, int *cl_pid, siginfo_t *info, int *pow)
{
	*c = 0;
	*pow = 0;
	*cl_pid = info->si_pid;
}

void	handel_pid(int *cl_pid, int current_pid)
{
	if (*cl_pid == 0)
		*cl_pid = current_pid;
}

void	handel_sig(int x, siginfo_t *info, void *ptr)
{
	static int	c;
	static int	pow;
	static int	cl_pid;

	(void)ptr;
	handel_pid(&cl_pid, info->si_pid);
	if (x == SIGUSR1)
	{
		if (cl_pid != info->si_pid)
			reset_in_casse_failure(&c, &cl_pid, info, &pow);
		handel_sig1(&c, &pow, cl_pid);
	}
	else if (x == SIGUSR2)
	{
		if (cl_pid != info->si_pid)
			reset_in_casse_failure(&c, &cl_pid, info, &pow);
		handel_sig2(&c, &pow, cl_pid);
	}
}
