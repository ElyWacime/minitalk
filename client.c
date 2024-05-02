/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:30:43 by welyousf          #+#    #+#             */
/*   Updated: 2024/05/02 11:48:16 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

int main(int    ac, char *av[])
{
    (void)ac;
    kill(atoi(av[1]), SIGUSR1);
    usleep(150);
    kill(atoi(av[1]), SIGUSR2);
    usleep(150);
    kill(atoi(av[1]), SIGUSR1);
    usleep(150);
    kill(atoi(av[1]), SIGUSR1);
    usleep(150);
    kill(atoi(av[1]), SIGUSR2);
    usleep(150);
    kill(atoi(av[1]), SIGUSR2);
    usleep(150);
    kill(atoi(av[1]), SIGUSR1);
    usleep(150);
    kill(atoi(av[1]), SIGUSR1);
}