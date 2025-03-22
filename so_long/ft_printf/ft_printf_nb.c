/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman <ktoraman@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:40:51 by ktoraman          #+#    #+#             */
/*   Updated: 2024/11/13 11:41:29 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_nb(unsigned int nb, int *i)
{
	if (nb >= 10)
	{
		ft_printf_nb(nb / 10, i);
		nb %= 10;
	}
	ft_printf_char(nb + '0', i);
}
