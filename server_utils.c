/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:42:14 by welyousf          #+#    #+#             */
/*   Updated: 2024/05/05 13:31:57 by welyousf         ###   ########.fr       */
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

void    power(int *i, int *POW, int *num, int *c)
{
        while (*i <= *POW)
        {
            *num *= 2;
            *i += 1;
        }
        *POW += 1;
        *c += *num;
}

void handel_sig1(int *c, int *POW)
{
    int i;
    int num;
    
    num = 1;
    i = 1;
    if (*POW > 0 && *POW < 8)
        power(&i, POW, &num, c);
    else if (*POW == 0)
    {
        *c += 1;
        *POW += 1;
    }
    if (*POW == 8)
    {
        if (*c == '\0')
            send_back(cl_pid[0]);
        else
        {
            ft_printf("%c", *c);
            *POW = 0;
            *c = 0;
        }
    }
}

void handel_sig2(int *c, int *POW)
{
    *POW += 1;
    if (*POW == 8)
    {
        if (*c == '\0')
            send_back(cl_pid[0]);
        else
        {
            ft_printf("%c", *c);
            *POW = 0;
            *c = 0;
        }
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

void    send_back(int pid)
{
    kill(pid, SIGUSR1);
}

void       reset_in_casse_failure(int *c, int *cl_pid, siginfo_t   *info, int *POW)
{
            *c = 0;
            *POW = 0;
            cl_pid[0] = info->si_pid;
            cl_pid[1] = info->si_pid;
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
            reset_in_casse_failure(&c, cl_pid, info, &POW);
        handel_sig1(&c, &POW);
    }
    else if (x == SIGUSR2)
    {
        if (cl_pid[0] != cl_pid[1])
            reset_in_casse_failure(&c, cl_pid, info, &POW);
        handel_sig2(&c, &POW);
    }
}
