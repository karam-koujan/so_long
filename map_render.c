/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:06:50 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/08 11:18:47 by kkoujan          ###   ########.fr       */
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

void	component_create(char **map, t_data mlx, char elm, char *file_path)
{
	void	*component;
	t_map	map_metadata;

	map_metadata.width = 60;
	map_metadata.height = 60;
	map_metadata.component = elm;
	component = mlx_xpm_file_to_image(mlx.mlx, file_path, \
									&map_metadata.width, &map_metadata.height);
	component_render(map, mlx, component, map_metadata);
}

void	map_render(char **map, t_data mlx)
{
	component_create(map, mlx, '1', "./textures/wall.xpm");
	component_create(map, mlx, 'C', "./textures/coin.xpm");
	component_create(map, mlx, '0', "./textures/road.xpm");
	component_create(map, mlx, 'E', "./textures/exit.xpm");
	component_create(map, mlx, 'P', "./textures/character.xpm");
	component_create(map, mlx, 'N', "./textures/enemy.xpm");
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
		mlx_destroy_image(vars->libx.mlx, img);
	}
	free(num);
}
