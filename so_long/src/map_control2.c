#include "so_long.h"

static int	validate_map_character(char c, int i, int j, t_map *map)
{
    // Check for unknown characters
    if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P')
    {
        ft_putendl_fd("Unknown character!", 2);
        return (1);
    }

    // Check if the map is surrounded by walls
    if (i == 0 || i == map->width - 1 || j == 1 || j == map->height)
    {
        if (c != '1')
        {
            ft_putendl_fd("Map is not surrounded by walls", 2);
            return (1);
        }
    }

    return (0);
}

int control_map_line(char *line, t_map *map, int j)
{
    int i;

    if (line[0] == '\n' || ft_strlen(line) == 0)
    {
        ft_putendl_fd("Unexpected new line in map!", 2);
        return (1);
    }
    i = 0;
    while (line[i + 1])
    {
        if (validate_map_character(line[i], i, j, map))
            return (1);
        i++;
    }
    i++;
    if (j == map->height && i == map->width - 1)
        return (0);
    if (i != map->width)
    {
        ft_putendl_fd("Map is not rectangular", 2);
        return (1);
    }
    return (0);
}
