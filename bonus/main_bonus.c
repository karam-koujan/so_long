/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:46:50 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/17 14:43:20 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		clean_up(vars);
		exit(0);
	}
	vars->map_metadata.height = 60;
	vars->map_metadata.width = 60;
	if (keycode == 13 || keycode == 1)
		player_v_move(vars->map, vars->player, keycode, vars);
	if (keycode == 0 || keycode == 2)
		player_h_move(vars->map, vars->player, keycode, vars);
	return (0);
}

int	close_window(t_vars *vars)
{
	clean_up(vars);
	exit(0);
	return (0);
}

char	**map_create(char *file_path)
{
	char	**map;
	int		fd;
	int		is_path_valid;

	fd = open(file_path, O_RDONLY, 0777);
	if (fd < 0)
		return (ft_printf("Error\nopen syscall failed\n"), exit(1), NULL);
	is_path_valid = check_path(file_path);
	if (!is_path_valid)
		return (ft_printf("Error\ninvalid path\n"), exit(1), NULL);
	map = read_map(fd, file_path);
	if (!map)
		return (ft_printf("Error\nallocation failed\n"), exit(1), NULL);
	return (map);
}

void	hooks(t_vars *vars)
{
	mlx_hook(vars->libx.win, 2, 0, key_hook, vars);
	mlx_hook(vars->libx.win, 17, 0, close_window, vars);
}

int	main(int ac, char **av)
{
	char	**map;
	t_data	mlx;
	t_vars	vars;

	if (ac != 2)
		return (ft_printf("Error\ninvalid path\n"), 1);
	mlx.mlx = mlx_init();
	vars.libx.mlx = mlx.mlx;
	if (!mlx.mlx)
		return (1);
	map = map_create(av[1]);
	if (!check_map(map) && ft_printf("Error\ninvalid map\n"))
		exit(1);
	mlx.height = 60 * count_rows(map);
	mlx.width = 60 * ft_strlen(map[0]);
	mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, av[0]);
	vars.libx = mlx;
	vars.map = map;
	vars.abs = absolute_path(av[0]);
	vars.player = NULL;
	map_render(map, &vars);
	vars.player = player(map, &vars);
	movement_count(vars.player->steps_count, &vars);
	hooks(&vars);
	return (mlx_loop(mlx.mlx), 0);
}
