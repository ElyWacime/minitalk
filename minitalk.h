/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:34:14 by welyousf          #+#    #+#             */
/*   Updated: 2024/05/06 13:10:17 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./ft_printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	print_pid(void);
void	handel_sig(int x, siginfo_t *info, void *ptr);
int		ft_atoi(const char *str);
void	send_char(unsigned char c, int pid);
void	func(int sig, siginfo_t *info, void *ptr);
void	power(int *i, int *pow, int *num, int *c);

#endif