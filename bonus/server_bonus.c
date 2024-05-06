/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:42:15 by welyousf          #+#    #+#             */
/*   Updated: 2024/05/06 13:03:04 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	*g_cl_pid;

void	power(int *i, int *pow, int *num, int *c)
{
	while (*i <= *pow)
	{
		*num *= 2;
		*i += 1;
	}
	*pow += 1;
	*c += *num;
}

void	print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("-------------- PID: %d ---------------\n", pid);
}

int	main(int ac, char *av[])
{
	struct sigaction	sa;

	(void)av;
	g_cl_pid = malloc(sizeof(int) * 2);
	sa.sa_sigaction = handel_sig;
	if (ac != 1)
	{
		ft_printf("%s\n", "Error");
		return (0);
	}
	print_pid();
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(1);
}
