/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman <ktoraman@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:12:32 by ktoraman          #+#    #+#             */
/*   Updated: 2024/11/13 11:36:32 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_int(int nb, int *i)
{
	long long	nbr;

	nbr = (long long) nb;
	if (nbr < 0)
	{
		ft_printf_char('-', i);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_printf_int(nbr / 10, i);
		nbr %= 10;
	}
	ft_printf_char(nbr + '0', i);
}
