/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:34:14 by welyousf          #+#    #+#             */
/*   Updated: 2024/05/03 14:40:31 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "./ft_printf/ft_printf.h"

void    print_pid(void);
void    handel_sig(int   x, siginfo_t   *info, void *ptr);
int	ft_atoi(const char *str);
void    send_char(unsigned char  c, int pid);

#endif