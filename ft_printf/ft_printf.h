/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welyousf <welyousf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:41:27 by welyousf          #+#    #+#             */
/*   Updated: 2023/12/30 15:41:42 by welyousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

typedef struct s_var
{
	int		varint;
	char	*str;
	char	*str2;
	int		count;
	int		trucker;
}			t_var;

int			ft_putchar_fd(char c, int fd);
size_t		ft_strlen(const char *str);
int			ft_putstr_fd(char *s, int fd);
int			tohexa(unsigned long long x);
int			ft_printf(const char *str, ...);
int			ft_puthexa_fd(size_t x, int *trucker);
int			ft_putchar_fd_a(char c, int *i);
int			ft_putnbr_fd(int n, int *trucker);
int			ft_putnbr_unsigned(unsigned int n, int *trucker);
int			tohexa_x(unsigned int a, char x);
int			ft_puthexa_x(unsigned int x, int *trucker, char a);

#endif
