/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:38:55 by alvera-v          #+#    #+#             */
/*   Updated: 2024/12/18 12:14:10 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int value, int *counter)
{
	if (value >= 10)
		ft_putunsigned(value / 10, counter);
	ft_putchar(value % 10 + '0');
	(*counter)++;
}
