/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:06:50 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/03 13:15:34 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	render_walls(char **map, t_data mlx, void *img, t_map meta_data)
{
	int	rows;
	int	cols;

	rows = 0;
	while (map[rows] != NULL)
	{
		cols = 0;
		while (map[rows][cols])
		{
			if (map[rows][cols] == '1')
			{
				mlx_put_image_to_window(mlx.mlx, mlx.win, img, cols * meta_data.width, \
										rows * meta_data.height);
			}
			cols++;
		}
		rows++;
	}
	return (1);
}



int	render_map(char **map, t_data mlx)
{
	void	*img;
	t_map	map_metadata;

	map_metadata.width = 100;
	map_metadata.height = 100;
	img = mlx_xpm_file_to_image(mlx.mlx, "./textures/walls.xpm", \
									&map_metadata.width, &map_metadata.height);
	render_walls(map, mlx, img, map_metadata);
	return (1);
}
