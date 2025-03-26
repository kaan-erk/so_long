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
	map->map = NULL;
	map->height = 0;
	map->width = 0;
	map->player_c = 0;
	map->exit_c = 0;
	map->coin_c = 0;
	return (map);
}

void	flood_fill_recursive(t_map *map, int x, int y)
{
    // Check if the current position is out of bounds or invalid
    if (x < 0 || y < 0 || x >= map->width || y >= map->height || map->map[y][x] == '1' || map->map[y][x] == 'x')
        return;

    // Mark the current cell as visited
    map->map[y][x] = 'x';

    // Recursively visit neighboring cells (up, down, left, right)
    flood_fill_recursive(map, x + 1, y); // Right
    flood_fill_recursive(map, x - 1, y); // Left
    flood_fill_recursive(map, x, y + 1); // Down
    flood_fill_recursive(map, x, y - 1); // Up
}

void	flood_fill(t_map *map)
{
    ft_printf("Player found at (%d, %d)\n", map->player.x, map->player.y);
    // Start flood-fill from the player's position
    flood_fill_recursive(map, map->player.x, map->player.y);
}

int	check_unreachable_elements(t_map *map)
{
    char	**map_copy;
    int		y;
    int		x;

    map_copy = copy_map(map->map, map->height);
    if (!map_copy)
        return (1);
    flood_fill_recursive(map, map->player.x, map->player.y);
    y = -1;
    while (++y < map->height)
    {
        x = -1;
        while (++x < map->width)
        {
            if (map->map[y][x] == 'C' && map_copy[y][x] != 'x')
                ft_printf("Unreachable coin at (%d, %d)\n", x, y);
            if (map->map[y][x] == 'E' && map_copy[y][x] != 'x')
                ft_printf("Unreachable exit at (%d, %d)\n", x, y);
        }
    }
	y = -1;
    while (++y < map->height)
        free(map_copy[y]);
    free(map_copy);
    return (0);
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
	if (file_name_check(tmp[0]) == 1 || map_read(tmp[0], map) == 1)
    {
        if (file_name_check(tmp[0]) == 1)
			ft_putendl_fd("Invalid file name", 2);
        free_array(tmp);
        return;
    }
	check_unreachable_elements(*map);
	free_array(tmp);
}
