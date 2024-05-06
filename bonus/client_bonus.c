/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:30:43 by welyousf          #+#    #+#             */
/*   Updated: 2024/05/06 13:20:59 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	main(int ac, char *av[])
{
	int					i;
	int					j;
	struct sigaction	sa;

	i = 1;
	if (ac != 3)
		return (0);
	sa.sa_sigaction = func;
	sigaction(SIGUSR1, &sa, NULL);
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			send_char((unsigned char)av[i][j], ft_atoi(av[1]));
		}
		send_char(0, ft_atoi(av[1]));
	}
	pause();
}
