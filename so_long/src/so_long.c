/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoraman <ktoraman@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:36:13 by ktoraman          #+#    #+#             */
/*   Updated: 2025/03/21 22:06:27 by ktoraman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	*map;

	map = NULL;
	if (ac == 2)
	{
		map = init_map();
		map_checker(av[1], &map);
		free_map(map);
	}
	else
	{
		ft_putendl_fd("Invalid number of arguments", 2);
		exit(1);
	}
}
