/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:42:15 by welyousf          #+#    #+#             */
/*   Updated: 2024/05/02 11:42:08 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int POW = 0;

void    handel_sig(int   x);

int main(int    ac, char    *av[])
{
    (void)av;
    if (ac != 1)
    {
        ft_printf("%s\n", "Error");
        return (0);
    }
    ft_printf("%s\n", "---------- Welcome to minitalk ----------");
    print_pid();
    signal(SIGUSR1, handel_sig);
    signal(SIGUSR2, handel_sig);
    while(1)
        pause();
}