/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:42:15 by welyousf          #+#    #+#             */
/*   Updated: 2024/05/07 13:12:07 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
