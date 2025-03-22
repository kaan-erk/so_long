/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman <ktoraman@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:54:28 by ktoraman          #+#    #+#             */
/*   Updated: 2024/11/13 18:00:05 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);
void	ft_printf_char(char c, int *i);
void	ft_printf_str(char *str, int *i);
void	ft_printf_hex(unsigned long long nb, int *i);
void	ft_printf_big_hex(unsigned long long nb, int *i);
void	ft_printf_int(int nb, int *i);
void	ft_printf_nb(unsigned int nb, int *i);
void	ft_printf_ptr(unsigned long long p, int *i);

#endif