/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman <ktoraman@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:50:51 by ktoraman          #+#    #+#             */
/*   Updated: 2025/03/21 22:12:33 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*init_map(void)
{
    t_map	*map;

    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
    {
        ft_putendl_fd("Memory allocation failed", 2);
        exit(1);
    }
    map->width = 0;
    map->height = 0;
    map->map = NULL;
    return (map);
}

void	map_checker(char *file_name, t_map **map)
{
    char **tmp;
    int	i;

    i = 0;
    tmp = ft_split(file_name, ' ');
    while (tmp[i + 1] != NULL)
        i++;
    if (i > 0)
    {
        free_array(tmp);
        way_out(22);
    }
	if (file_name_check(tmp[0]) == 1)
	{
		ft_putendl_fd("False file name", 2);
		free_array(tmp);
		exit(1);
	}
    map_read(tmp[0], map);
    free_array(tmp);
}
