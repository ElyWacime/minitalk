/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:30:43 by welyousf          #+#    #+#             */
/*   Updated: 2024/05/04 14:30:29 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int    ac, char *av[])
{
    int i;
    int j;

    i = 1;
    if (ac != 3)
        return (0);
    while (++i < ac)
    {
        j = -1;
        while (av[i][++j])
        {
            send_char((unsigned char)av[i][j], ft_atoi(av[1]));
        }
        
    }
}