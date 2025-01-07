/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:06:50 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/07 10:59:37 by kkoujan          ###   ########.fr       */
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
	return (mlx_destroy_image(mlx.mlx, img), mlx_destroy_image(mlx.mlx, bg), 0);
}

void	component_render_pos(t_data mlx, char **map, void *img, \
t_map map_metadata)
{
	if (map[map_metadata.y][map_metadata.x] != '1')
	{
		mlx_put_image_to_window(mlx.mlx, mlx.win, img, map_metadata.x * \
					60, map_metadata.y * 60);
	}
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
	component_render(map, mlx, component, map_metadata);
	map_metadata.component = 'N';
	component = mlx_xpm_file_to_image(mlx.mlx, "./textures/enemy.xpm", \
									&map_metadata.width, &map_metadata.height);
	return (component_render(map, mlx, component, map_metadata), 1);
}


void	init_numbers(char	**numbers)
{
	numbers[0] = "./textures/0.xpm";
	numbers[1] = "./textures/1.xpm";
	numbers[2] = "./textures/2.xpm";
	numbers[3] = "./textures/3.xpm";
	numbers[4] = "./textures/4.xpm";
	numbers[5] = "./textures/5.xpm";
	numbers[6] = "./textures/6.xpm";
	numbers[7] = "./textures/7.xpm";
	numbers[8] = "./textures/8.xpm";
	numbers[9] = "./textures/9.xpm";
}

void	movement_count(int count, t_vars *vars)
{
	char		*numbers[10];
	void		*img;
	int			size;
	char		*num;
	int			i;

	size = 60;
	i = 0;
	init_numbers(numbers);
	num = ft_itoa(count);
	while (num[i])
	{
		img = mlx_xpm_file_to_image(vars->libx.mlx, numbers[num[i] - '0'], \
		&size, &size);
		mlx_put_image_to_window(vars->libx.mlx, vars->libx.win, img, i * \
					size, 0 * size);
		i++;
	}
	free(num);
}
