/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:30:43 by welyousf          #+#    #+#             */
/*   Updated: 2024/05/03 11:24:54 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int    ac, char *av[])
{
    int i;
    int j;

    i = 1;
    while (++i < ac)
    {
        j = -1;
        while (av[i][++j])
        {
            ft_printf("ENTER!!!!\n");
            send_char((unsigned char)av[i][j], ft_atoi(av[1]));
        }
        
    }
    ft_printf("av[1]: %d\n", ft_atoi(av[1]));
}