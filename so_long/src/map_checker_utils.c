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

void	place_map(int fd, t_map **map)
{
	char	*line;
	int		i;
	t_map	*tmp;

	tmp = *map;
	i = 0;
	tmp->map = (char **)malloc(sizeof(char *) * 100);
	while ((line = get_next_line(fd)) > 0)
	{
		if (i == 0)
			tmp->width = ft_strlen(line);
		tmp->map[i] = ft_strdup(line);
		tmp->height++;
		i++;
		free(line);
	}
	tmp->width--;
	free(line);
}

void	map_read(char *file_name, t_map **map)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd(strerror(errno), 2);
		return ;
	}
	place_map(fd, map);
	close(fd);
	ft_printf("%d\n", (*map)->height);
	ft_printf("%d\n", (*map)->width);
	ft_printf("%s", (*map)->map[0]);
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