/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman <ktoraman@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:58:46 by ktoraman          #+#    #+#             */
/*   Updated: 2025/03/21 22:19:51 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_map_line(char *line, t_map *tmp, int i)
{
    if (i == 0)
        tmp->width = ft_strlen(line);
    if (control_map_line(line, tmp, i + 1) || element_control(line, tmp, i))
    {
        free(line);
        return (1);
    }
    tmp->map[i] = ft_strdup(line);
    if (tmp->map[i] == NULL)
    {
        ft_putendl_fd("Memory allocation failed", 2);
        free(line);
        return (1);
    }
    free(line);
    return (0);
}

static int	place_map(int fd1, int fd2, t_map **map)
{
    char	*line;
    int		i;
    t_map	*tmp;

    tmp = *map;
    i = 0;
    while ((line = get_next_line(fd1)) != NULL)
    {
        tmp->height++;
        free(line);
    }
    tmp->map = (char **)ft_calloc(tmp->height, sizeof(char *));
    if (tmp->map == NULL)
    {
        ft_putendl_fd("Memory allocation failed", 2);
        return (1);
    }
    while ((line = get_next_line(fd2)) != NULL)
    {
        if (process_map_line(line, tmp, i))
            return (1);
        i++;
    }
    ft_printf("Final i: %d\n", i);
    ft_printf("Final width: %d\n", tmp->width);
    ft_printf("Final height: %d\n", tmp->height);
    return (0);
}

int	map_read(char *file_name, t_map **map)
{
    int	fd1;
    int	fd2;

    fd1 = open(file_name, O_RDONLY);
    if (fd1 < 0)
    {
        ft_putendl_fd(strerror(errno), 2);
        return (1);
    }
    fd2 = open(file_name, O_RDONLY);
    if (fd2 < 0)
    {
        ft_putendl_fd(strerror(errno), 2);
        close(fd1);
        return (1);
    }
    if (place_map(fd1, fd2, map) == 1)
    {
        close(fd1);
        close(fd2);
        return (1);
    }
    close(fd1);
    close(fd2);
    return (0);
}

int	file_name_check(char *file_name)
{
    int	i;

    i = 0;
    while (file_name[i] != '.')
        i++;
    if (ft_strncmp(file_name + i, ".ber", 4) == 0 && file_name[i + 4] == '\0')
        return (0);
    else
        return (1);
}

char	**copy_map(char **original_map, int height)
{
    char	**map_copy;
    int		i;

    map_copy = (char **)malloc(sizeof(char *) * height);
    if (!map_copy)
    {
        ft_putendl_fd("Memory allocation failed for map copy", 2);
        return (NULL);
    }
    i = 0;
    while (i < height)
    {
        map_copy[i] = ft_strdup(original_map[i]);
        if (!map_copy[i])
        {
            ft_putendl_fd("Memory allocation failed for map copy", 2);
            while (--i >= 0)
                free(map_copy[i]);
            free(map_copy);
            return (NULL);
        }
        i++;
    }
    return (map_copy);
}
