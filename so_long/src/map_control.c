#include "so_long.h"

int check_player(char location, t_map *tmp, int i, int tmp_height)
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
        tmp->player.y = tmp_height;
        ft_printf("Player found at (%d, %d)\n", tmp->player.x, tmp->player.y);
    }
    return (0);
}

int check_exit(char location, t_map *tmp, int i, int tmp_height)
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
        tmp->exit.y = tmp_height;
        ft_printf("Exit found at (%d, %d)\n", tmp->exit.x, tmp->exit.y);
    }
    return (0);
}

void check_coin(char location, t_map *tmp, int i, int tmp_height)
{
    if (location == 'C')
    {
        tmp->coin_c++;
        tmp->coin.x = i;
        tmp->coin.y = tmp_height;
        ft_printf("Coin found at (%d, %d)\n", tmp->coin.x, tmp->coin.y);
    }
}

int element_control(char *line, t_map *tmp, int tmp_height)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (check_player(line[i], tmp, i, tmp_height))
            return (1);
        if (check_exit(line[i], tmp, i, tmp_height))
            return (1);
        check_coin(line[i], tmp, i, tmp_height);
        i++;
    }
    if (tmp->height == tmp_height + 1 && (tmp->player_c == 0 || tmp->exit_c == 0 || tmp->coin_c == 0))
    {
        if (tmp->player_c == 0)
            ft_putendl_fd("Player not found!", 2);
        if (tmp->exit_c == 0)
            ft_putendl_fd("Exit not found!", 2);
        if (tmp->coin_c == 0)
            ft_putendl_fd("No coins found!", 2);
        return (1);
    }
    return (0);
}
