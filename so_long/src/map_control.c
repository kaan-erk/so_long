#include "so_long.h"

int control_map_line(char *line, int width, int j, int height)
{
    int i;

    i = 0;
    while (line[i + 1])
    {
        if (line[i] != '1' && line[i] != '0' && line[i] != 'C' && line[i] != 'E' && line[i] != 'P')
        {
            ft_putendl_fd("Unknown character!", 2);
            return (1);
        }
        else if (i == 0 || i == width - 1 || j == 1 || j == height)
        {
            if (line[i] != '1')
            {
                ft_putendl_fd("Map is not surrounded by walls", 2);
                return (1);
            }
        }
        i++;
    }
    i++;
    if (j == height && i == width - 1)
        return (0);
    if (i != width)
    {
        ft_putendl_fd("Map is not rectengular", 2);
        return (1);
    }
    return (0);
}

int check_player(char location, t_map *tmp, int i)
{
    if (location == 'P')
    {
        if (tmp->player_c == 1)
        {
            ft_putendl_fd("More than one player!", 2);
            return (1);
        }
        tmp->player_c = 1;
        tmp->player.x = i;
        tmp->player.y = tmp->height;
        ft_printf("Player found at (%d, %d)\n", tmp->player.x, tmp->player.y);
    }
    return (0);
}

int check_exit(char location, t_map *tmp, int i)
{
    if (location == 'E')
    {
        if (tmp->exit_c == 1)
        {
            ft_putendl_fd("More than one exit!", 2);
            return (1);
        }
        tmp->exit_c = 1;
        tmp->exit.x = i;
        tmp->exit.y = tmp->height;
        ft_printf("Exit found at (%d, %d)\n", tmp->exit.x, tmp->exit.y);
    }
    return (0);
}

void check_coin(char location, t_map *tmp, int i)
{
    if (location == 'C')
    {
        tmp->coin_c++;
        tmp->coin.x = i;
        tmp->coin.y = tmp->height;
        ft_printf("Coin found at (%d, %d)\n", tmp->coin.x, tmp->coin.y);
    }
}

int element_control(char *line, t_map *tmp, int tmp_height)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (check_player(line[i], tmp, i))
            return (1);
        if (check_exit(line[i], tmp, i))
            return (1);
        check_coin(line[i], tmp, i);
        i++;
    }
    if (tmp->height == tmp_height && tmp->player_c == 0)
    {
        ft_putendl_fd("Player not found!", 2);
        return (1);
    }
    if (tmp->height == tmp_height && tmp->exit_c == 0)
    {
        ft_putendl_fd("Exit not found!", 2);
        return (1);
    }
    return (0);
}