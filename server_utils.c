/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:42:14 by welyousf          #+#    #+#             */
/*   Updated: 2024/05/03 12:44:53 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

extern int POW;
extern int c;

void    print_pid(void)
{
    pid_t   pid;
    pid = getpid();
    ft_printf("-------------- PID: %d ---------------\n", pid);
}

void handel_sig1()
{
    int i;
    int num;
    
    num = 1;
    i = 1;
    if (POW > 0 && POW < 8)
    {
        // ft_printf("00: pow = %d\n", POW);
        while (i <= POW)
        {
            num *= 2;
            i++;
        }
        POW += 1;
        c += num;
        // ft_printf("00 : c = %d\tnum = %d\n", c, num);
    }
    else if (POW == 0)
    {
        // ft_printf("01 : pow == %d\n", POW);
        c += 1;
        POW += 1;
    }
    if (POW == 8)
    {
        ft_printf("%c", c);
        // ft_printf("02 : pow = %d\n", POW);
        // ft_printf("this is final char : %c\tthis is final int : %d\n", c, c);
        POW = 0;
        c = 0;
    }
}

void handel_sig2(void)
{
    // ft_printf("sig2 : pow == %d\n", POW);
    POW += 1;
    if (POW == 8)
    {
        ft_printf("%c", c);
        // ft_printf("sig2 final char : %c\tfinal int: %d\n", c, c);
        POW = 0;
        c = 0;
    }
}

void    handel_sig(int   x)
{
    if (x == SIGUSR1)
    {
        handel_sig1();
    }
    else if (x == SIGUSR2)
    {
        handel_sig2();
    }
}
