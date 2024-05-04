/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:42:14 by welyousf          #+#    #+#             */
/*   Updated: 2024/05/04 19:17:27 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

extern int  *cl_pid;

void    print_pid(void)
{
    pid_t   pid;
    pid = getpid();
    ft_printf("-------------- PID: %d ---------------\n", pid);
}

void handel_sig1(int *c, int *POW, int **len)
{
    int i;
    int num;
    
    num = 1;
    i = 1;
    if (*POW > 0 && *POW < 8)
    {
        while (i <= *POW)
        {
            num *= 2;
            i++;
        }
        *POW += 1;
        *c += num;
    }
    else if (*POW == 0)
    {
        *c += 1;
        *POW += 1;
    }
    if (*POW == 8)
    {
        if (*c == '\0')
        {
            ft_printf("\nback slash arived\n");
            send_back(cl_pid[2], cl_pid[0]);
        }
        ft_printf("%c", *c);
        *POW = 0;
        *c = 0;
        *(*len + 2) += 1;
    }
}

void handel_sig2(int *c, int *POW, int **len)
{
    *POW += 1;
    if (*POW == 8)
    {
        if (*c == '\0')
        {
            ft_printf("\nback slash arived\n");
            send_back(cl_pid[2], cl_pid[0]);
        }
        ft_printf("%c", *c);
        *POW = 0;
        *c = 0;
        *(*len + 2) += 1;
    }
}

void    check_pid(int pid, int *pids)
{
    static int  cnt;

    if (cnt == 0)
    {
        pids[0] = pid;
        pids[1] = pid;
        cnt += 1;
    }
    else
        pids[1] = pid;
}

void    send_back(int len, int pid)
{
    int i;

    i = 1;
    while (i < 32)
    {
        if ((len >> i) & 1)
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

void    handel_sig(int   x, siginfo_t   *info, void *ptr)
{
    static int  c;
    static int  POW;

    (void)ptr;
    check_pid(info->si_pid, cl_pid);
    if (x == SIGUSR1)
    {
        if (cl_pid[0] != cl_pid[1])
        {
            c = 0;
            POW = 0;
            cl_pid[0] = info->si_pid;
            cl_pid[1] = info->si_pid;
        }
        handel_sig1(&c, &POW, &cl_pid);
    }
    else if (x == SIGUSR2)
    {
        if (cl_pid[0] != cl_pid[1])
        {
            c = 0;
            POW = 0;
            cl_pid[0] = info->si_pid;
            cl_pid[1] = info->si_pid;

        }
        handel_sig2(&c, &POW, &cl_pid);
    }
    // ft_printf("len == %d\n", cl_pid[2]);
}
