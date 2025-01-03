/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:06:50 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/03 14:00:12 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	render_walls(char **map, t_data mlx, void *img, t_map map_metadata)
{
	int	rows;
	size_t	cols;
	rows = 0;
	while (map[rows] != NULL)
	{
		cols = 0;
		while (cols < ft_strlen(map[rows]))
		{
			if (map[rows][cols] == map_metadata.component)
			{
				mlx_put_image_to_window(mlx.mlx, mlx.win, img, cols * map_metadata.width, \
											rows * map_metadata.height);
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
	void	*coin;
	t_map	map_metadata;

	map_metadata.width = 100;
	map_metadata.height = 100;
	map_metadata.component = '1';
	img = mlx_xpm_file_to_image(mlx.mlx, "./textures/walls.xpm", \
									&map_metadata.width, &map_metadata.height);
	render_walls(map, mlx, img, map_metadata);
	map_metadata.component = 'P';
	mlx_destroy_image(mlx.mlx,img);
	coin =  mlx_xpm_file_to_image(mlx.mlx, "./textures/coin.xpm", \
									&map_metadata.width, &map_metadata.height);
	render_walls(map, mlx, coin, map_metadata);
	return (1);
}
