/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:06:50 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/03 15:37:11 by kkoujan          ###   ########.fr       */
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
	t_map	map_metadata;

	map_metadata.width = 100;
	map_metadata.height = 100;
	map_metadata.component = '1';
	img = mlx_xpm_file_to_image(mlx.mlx, "./textures/walls.xpm", \
									&map_metadata.width, &map_metadata.height);
	component_render(map, mlx, img, map_metadata);
	map_metadata.component = 'C';
	map_metadata.width = 50;
	map_metadata.height = 50;
	coin =  mlx_xpm_file_to_image(mlx.mlx, "./textures/coin.xpm", \
									&map_metadata.width, &map_metadata.height);
	component_render(map, mlx, coin, map_metadata);
	return (1);
}
