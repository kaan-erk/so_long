/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman <ktoraman@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:36:10 by ktoraman          #+#    #+#             */
/*   Updated: 2025/03/21 21:46:22 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include <errno.h>
# include <string.h>
# include <fcntl.h>

typedef struct coord
{
	int	x;
	int	y;
}			t_coord;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		coin_c;
	int		exit_c;
	int		player_c;
	t_coord	player;
	t_coord	exit;
	t_coord	coin;
}			t_map;


void	map_checker(char *file, t_map **map);
int		file_name_check(char *file);
void	free_array(char **tmp);
void	way_out(int i);
int	map_read(char *file_name, t_map **map);
t_map	*init_map(void);
void	free_map(t_map *map);
int element_control(char *line, t_map *tmp, int height);
int control_map_line(char *line, t_map *map, int j);
char	**copy_map(char **original_map, int height);

#endif