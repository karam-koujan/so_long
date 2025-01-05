/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:06:50 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/05 08:21:28 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	component_render(char **map, t_data mlx, void *img, t_map map_metadata)
{
	int	rows;
	int	cols;

	rows = 0;
	while (map[rows] != NULL)
	{
		cols = 0;
		while (map[rows][cols])
		{
			if (map[rows][cols] == map_metadata.component)
			{
				mlx_put_image_to_window(mlx.mlx, mlx.win, img, cols * \
						map_metadata.width, rows * map_metadata.height);
			}
			cols++;
		}
		rows++;
	}
	return (1);
}

int	map_render(char **map, t_data mlx)
{
	void	*img;
	void	*coin;
	void	*road;
	void	*exit;
	t_map	map_metadata;

	map_metadata.width = 60;
	map_metadata.height = 60;
	map_metadata.component = '1';
	img = mlx_xpm_file_to_image(mlx.mlx, "./textures/wall.xpm", \
									&map_metadata.width, &map_metadata.height);
	component_render(map, mlx, img, map_metadata);
	map_metadata.component = 'C';

	coin =  mlx_xpm_file_to_image(mlx.mlx, "./textures/coin.xpm", \
									&map_metadata.width, &map_metadata.height);
	component_render(map, mlx, coin, map_metadata);
	road =  mlx_xpm_file_to_image(mlx.mlx, "./textures/road.xpm", \
									&map_metadata.width, &map_metadata.height);
	map_metadata.component = '0';
	component_render(map, mlx, road, map_metadata);
	exit =  mlx_xpm_file_to_image(mlx.mlx, "./textures/exit.xpm", \
									&map_metadata.width, &map_metadata.height);
	map_metadata.component = 'E';
	component_render(map, mlx, exit, map_metadata);
	return (1);
}
