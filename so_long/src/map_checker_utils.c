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

void	place_map(int fd1, int fd2, t_map **map)
{
    char	*line;
    int		i;
    t_map	*tmp;

    tmp = *map;
    i = 0;
    tmp->height = 0;
    tmp->width = 0;
    while ((line = get_next_line(fd1)) != NULL)
    {
        tmp->height++;
        free(line);
    }
    tmp->map = (char **)malloc(sizeof(char *) * tmp->height);
    if (tmp->map == NULL)
    {
        ft_putendl_fd("Memory allocation failed", 2);
        return ;
    }
    while ((line = get_next_line(fd2)) != NULL)
    {
        if (i == 0)
            tmp->width = ft_strlen(line);
		if (control_map_line(line, tmp->width, i + 1, tmp->height) || element_control(line, tmp, i))
		{
			free(line);
			return ;
		}
        tmp->map[i] = ft_strdup(line);
        if (tmp->map[i] == NULL)
        {
            ft_putendl_fd("Memory allocation failed", 2);
            free(line);
            return ;
        }
        i++;
        free(line);
    }
    ft_printf("Final i: %d\n", i);
    ft_printf("Final width: %d\n", tmp->width);
    ft_printf("Final height: %d\n", tmp->height);
}

void	map_read(char *file_name, t_map **map)
{
    int	fd1;
    int	fd2;

    fd1 = open(file_name, O_RDONLY);
    if (fd1 < 0)
    {
        ft_putendl_fd(strerror(errno), 2);
        return ;
    }
    fd2 = open(file_name, O_RDONLY);
    if (fd2 < 0)
    {
        ft_putendl_fd(strerror(errno), 2);
        close(fd1);
        return ;
    }
    place_map(fd1, fd2, map);
    close(fd1);
    close(fd2);
}

int	file_name_check(char *file_name)
{
    int	i;

    i = 0;
    while (file_name[i] != '.')
        i++;
    if (ft_strncmp(file_name + i, ".ber", 4) == 0 && file_name[i + 4] == '\0')
    {
        ft_printf("True file name\n");
        return (0);
    }
    else
        return (1);
}