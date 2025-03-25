/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:11:29 by alvera-v          #+#    #+#             */
/*   Updated: 2025/02/04 18:16:16 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *string, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s, int *counter);
void	ft_putptr(unsigned long long value, int *counter);
void	ft_putnbr(int n, int *counter);
void	ft_puthex(unsigned int value, const char c, int *counter);
void	ft_putunsigned(unsigned int value, int *counter);

#endif
