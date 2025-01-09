/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:46:50 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/09 12:55:26 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		exit(0);
		return (0);
	}
	vars->map_metadata.height = 60;
	vars->map_metadata.width = 60;
	if (keycode == 13 || keycode == 0)
	{
		vars->player->steps_count++;
		ft_printf("%i\n", vars->player->steps_count);
		movement_count(vars->player->steps_count, vars);
		player_v_move(vars->map, vars->player, keycode, vars);
	}
	if (keycode == 1 || keycode == 2)
	{
		vars->player->steps_count++;
		ft_printf("%i\n", vars->player->steps_count);
		movement_count(vars->player->steps_count, vars);
		player_h_move(vars->map, vars->player, keycode, vars);
	}
	return (0);
}

int	close_window(void)
{
	exit(0);
	return (0);
}

char	**map_create(char *file_path)
{
	char	**map;
	int		fd;
	int		is_path_valid;

	fd = open(file_path, O_RDONLY, 0777);
	is_path_valid = check_path(file_path);
	if (!is_path_valid || fd < 0)
	{
		ft_printf("Error\ninvalid path\n");
		exit(1);
		return (NULL);
	}
	map = read_map(fd, file_path);
	if (!map)
	{
		ft_printf("Error\ninvalid path\n");
		exit(1);
		return (NULL);
	}
	return (map);
}

void	hooks(t_vars *vars)
{
	mlx_key_hook(vars->libx.win, key_hook, vars);
	mlx_hook(vars->libx.win, 17, 0, close_window, vars);
}

int	main(int ac, char **av)
{
	char	**map;
	t_data	mlx;
	t_vars	vars;

	if (ac != 2)
		return (1);
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (1);
	map = map_create(av[1]);
	if (!check_map(map) && ft_printf("Error\nThe map you gave is invalid\n"))
	{
		free_arr(map, count_rows(map));
		exit(1);
	}
	mlx.height = 60 * count_rows(map);
	mlx.width = 60 * ft_strlen(map[0]);
	mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, av[0]);
	vars.libx = mlx;
	vars.map = map;
	vars.abs = absolute_path(av[0]);
	map_render(map, &vars);
	vars.player = player(map, &vars);
	movement_count(vars.player->steps_count, &vars);
	hooks(&vars);
	return (mlx_loop(mlx.mlx), free(vars.player), free(mlx.mlx), 0);
}
