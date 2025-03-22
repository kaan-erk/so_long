/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman <ktoraman@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:14:29 by ktoraman          #+#    #+#             */
/*   Updated: 2024/11/13 17:04:28 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_str(char *str, int *i)
{
	int	x;

	if (!str)
	{
		ft_printf_str("(null)", i);
		return ;
	}
	x = 0;
	while (str[x])
	{
		write(1, &str[x], 1);
		x++;
	}
	*i += x;
}
