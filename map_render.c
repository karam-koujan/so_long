/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:06:50 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/09 14:06:04 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	component_render(char **map, t_data mlx, void *img, t_map map_d)
{
	int		rows;
	int		cols;


	rows = 0;
	while (map[rows] != NULL)
	{
		cols = 0;
		while (map[rows][cols])
		{
			if (map_d.component == '0' && map[rows][cols] != '0' && \
			map[rows][cols] != '1')
				mlx_put_image_to_window(mlx.mlx, mlx.win, img, cols * \
						map_d.width, rows * map_d.height);
			if (map[rows][cols] == map_d.component)
			{
				mlx_put_image_to_window(mlx.mlx, mlx.win, img, cols * \
						map_d.width, rows * map_d.height);
			}
			cols++;
		}
		rows++;
	}
	return (mlx_destroy_image(mlx.mlx, img), 0);
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
	map_metadata.abs = file_path;
	component = mlx_xpm_file_to_image(mlx.mlx, file_path, \
									&map_metadata.width, &map_metadata.height);
	component_render(map, mlx, component, map_metadata);
	free(file_path);
}

void	map_render(char **map, t_vars *vars)
{
	char	*abs;

	abs = vars->abs;
	if (vars->libx.width > 5120 || vars->libx.height > 1440)
	{
		ft_printf("Error\nmap is to long to fit the monitor\n");
		exit(1);
	}
	component_create(map, vars->libx, '0', ft_strjoin(abs, \
	"textures/road.xpm"));
	component_create(map, vars->libx, '1', ft_strjoin(abs, \
	"textures/wall.xpm"));
	component_create(map, vars->libx, 'C', ft_strjoin(abs, \
	"textures/coin.xpm"));
	component_create(map, vars->libx, 'E', ft_strjoin(abs, \
	"textures/exit.xpm"));
	component_create(map, vars->libx, 'P', ft_strjoin(abs, \
	"textures/character.xpm"));
	component_create(map, vars->libx, 'N', ft_strjoin(abs, \
	"textures/enemy.xpm"));
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
	init_numbers(numbers, vars);
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
	i = -1;
	while (++i < 10)
		free(numbers[i]);
	free(num);
}
