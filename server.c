/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:38:36 by welyousf          #+#    #+#             */
/*   Updated: 2024/05/02 12:03:15 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

extern int POW;

void    print_pid(void)
{
    pid_t   pid;
    pid = getpid();
    ft_printf("-------------- PID: %d ---------------\n", pid);
}

void    handel_sig1(int *c)
{
    int i;
    int num;
    
    num = 1;
    i = 0;
    if (POW <= 8 && POW > 0)
    {
        while (i <= POW)
            num *= 2;
        POW += 1;
        c += num;
        ft_printf("\nEnter00\n");
    }
    else if (POW == 0)
    {
        *c += 1;
        POW += 1;
        ft_printf("\nEnter01\t%d\n", POW);
    }
    if (POW == 8)
    {
        ft_printf("%c", *c);
        POW = 0;
    }
    ft_printf("\nEnter\n");
}

void    handel_sig2(void)
{
    POW += 1;
    ft_printf("%d", POW);
    ft_printf("ENTER SIG2\n");
}

void    handel_sig(int   x)
{
    int c;
    
    if (x == SIGUSR1)
    {
        handel_sig1(&c);
    }
    else if (x == SIGUSR2)
    {
        handel_sig2();
    }
}
