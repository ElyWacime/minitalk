/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:42:14 by welyousf          #+#    #+#             */
/*   Updated: 2024/05/06 13:03:10 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

extern int	*g_cl_pid;

void	handel_sig1(int *c, int *pow)
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
			kill(g_cl_pid[0], SIGUSR1);
		else
		{
			write(1, (char *)c, 1);
			*pow = 0;
			*c = 0;
		}
	}
}

void	handel_sig2(int *c, int *pow)
{
	*pow += 1;
	if (*pow == 8)
	{
		if (*c == '\0')
			kill(g_cl_pid[0], SIGUSR1);
		else
		{
			write(1, (char *)c, 1);
			*pow = 0;
			*c = 0;
		}
	}
}

void	check_pid(int pid, int *pids)
{
	static int	cnt;

	if (cnt == 0)
	{
		pids[0] = pid;
		pids[1] = pid;
		cnt += 1;
	}
	else
		pids[1] = pid;
}

void	reset_in_casse_failure(int *c, int *cl_pid, siginfo_t *info, int *pow)
{
	*c = 0;
	*pow = 0;
	cl_pid[0] = info->si_pid;
	cl_pid[1] = info->si_pid;
}

void	handel_sig(int x, siginfo_t *info, void *ptr)
{
	static int	c;
	static int	pow;

	(void)ptr;
	check_pid(info->si_pid, g_cl_pid);
	if (x == SIGUSR1)
	{
		if (g_cl_pid[0] != g_cl_pid[1])
			reset_in_casse_failure(&c, g_cl_pid, info, &pow);
		handel_sig1(&c, &pow);
	}
	else if (x == SIGUSR2)
	{
		if (g_cl_pid[0] != g_cl_pid[1])
			reset_in_casse_failure(&c, g_cl_pid, info, &pow);
		handel_sig2(&c, &pow);
	}
}
