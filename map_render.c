/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:06:50 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/05 11:30:37 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	component_render(char **map, t_data mlx, void *img, t_map map_metadata)
{
	int		rows;
	int		cols;
	void	*bg;

	rows = 0;
	bg = mlx_xpm_file_to_image(mlx.mlx, "./textures/road.xpm", \
									&map_metadata.width, &map_metadata.height);
	while (map[rows] != NULL)
	{
		cols = 0;
		while (map[rows][cols])
		{
			if (map[rows][cols] == map_metadata.component)
			{
				mlx_put_image_to_window(mlx.mlx, mlx.win, bg, cols * \
						map_metadata.width, rows * map_metadata.height);				
				mlx_put_image_to_window(mlx.mlx, mlx.win, img, cols * \
						map_metadata.width, rows * map_metadata.height);
			}
			cols++;
		}
		rows++;
	}
	mlx_destroy_image(mlx.mlx, img);
	return (0);
}

int	component_render_pos(t_data mlx, void *img, t_map map_metadata)
{
	mlx_put_image_to_window(mlx.mlx, mlx.win, img, map_metadata.x * \
					map_metadata.width, map_metadata.y * map_metadata.height);
	return (0);
}

int	map_render(char **map, t_data mlx)
{
	void	*component;
	t_map	map_metadata;

	map_metadata.width = 60;
	map_metadata.height = 60;
	map_metadata.component = '1';
	component = mlx_xpm_file_to_image(mlx.mlx, "./textures/wall.xpm", \
									&map_metadata.width, &map_metadata.height);
	component_render(map, mlx, component, map_metadata);
	map_metadata.component = 'C';
	component = mlx_xpm_file_to_image(mlx.mlx, "./textures/coin.xpm", \
									&map_metadata.width, &map_metadata.height);
	component_render(map, mlx, component, map_metadata);
	component = mlx_xpm_file_to_image(mlx.mlx, "./textures/road.xpm", \
									&map_metadata.width, &map_metadata.height);
	map_metadata.component = '0';
	component_render(map, mlx, component, map_metadata);
	component = mlx_xpm_file_to_image(mlx.mlx, "./textures/exit.xpm", \
									&map_metadata.width, &map_metadata.height);
	map_metadata.component = 'E';
	component_render(map, mlx, component, map_metadata);
	map_metadata.component = 'P';
	component = mlx_xpm_file_to_image(mlx.mlx, "./textures/character.xpm", \
									&map_metadata.width, &map_metadata.height);
	return (component_render(map, mlx, component, map_metadata), 1);
}
