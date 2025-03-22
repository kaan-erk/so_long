/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman <ktoraman@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:52:38 by ktoraman          #+#    #+#             */
/*   Updated: 2024/11/13 18:54:29 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_hex(unsigned long long nb, int *i)
{
	if (nb >= 16)
		ft_printf_hex(nb / 16, i);
	ft_printf_char("0123456789abcdef"[nb % 16], i);
}

void	ft_printf_big_hex(unsigned long long nb, int *i)
{
	if (nb >= 16)
		ft_printf_big_hex(nb / 16, i);
	ft_printf_char("0123456789ABCDEF"[nb % 16], i);
}

void	ft_printf_ptr(unsigned long long p, int *i)
{
	if (!p)
	{
		ft_printf_str("(nil)", i);
		return ;
	}
	ft_printf_str("0x", i);
	if (p >= 16)
		ft_printf_hex(p / 16, i);
	ft_printf_char("0123456789abcdef"[p % 16], i);
}
