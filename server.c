/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:42:15 by welyousf          #+#    #+#             */
/*   Updated: 2024/05/04 18:56:08 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int  *cl_pid;

int main(int    ac, char    *av[])
{
    struct sigaction    sa;
    
    (void)av;
    cl_pid = malloc(sizeof(int) * 3);
    sa.sa_sigaction = handel_sig;
    if (ac != 1)
    {
        ft_printf("%s\n", "Error");
        return (0);
    }
    print_pid();
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while(1)
        sleep(1);
}
