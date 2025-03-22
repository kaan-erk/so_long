/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman <ktoraman@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:07:23 by ktoraman          #+#    #+#             */
/*   Updated: 2025/03/21 18:35:21 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **tmp)
{
    int	i;

    i = 0;
    while (tmp[i])
    {
        free(tmp[i]);
        i++;
    }
    free(tmp);
}

void	way_out(int i)
{
    errno = i;
    ft_printf("%s\n", strerror(errno));	
    exit(EXIT_FAILURE);
}