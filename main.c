/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:46:50 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/07 11:03:47 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void f()
{
	system("leaks so_long");
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		f();
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
	f();
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	char	**map;
	int		fd;
	t_data	mlx;
	t_vars 	vars;

	if (ac == 1 || ac > 2)
	{
		return (1);
	}
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (1);
	fd = open(av[1], O_RDONLY, 0777);
	if (fd < 0)
		return (1);
	map = read_map(fd, av[1]);
	if (!map)
		return (1);
	char **c_map = copy_map(map);
	if (!c_map)
		return (1);
	if (check_map(map))
	{
		mlx.height = 60 * count_rows(map);
		mlx.width = 60 * ft_strlen(map[0]);
		mlx.win = mlx_new_window(mlx.mlx, mlx.width, \
									mlx.height, av[0]);
		map_render(c_map, mlx);
	}
	else
	{
		ft_printf("Error\nThe map you gave is invalid\n");
		free_arr(map, count_rows(map));
		free_arr(c_map, count_rows(c_map));
		atexit(f);
		exit(1);
	}
	vars.libx = mlx;
	vars.map = c_map;
	vars.player = player(c_map, &vars);
	movement_count(vars.player->steps_count, &vars);
	free_arr(map, count_rows(map));
	mlx_key_hook(mlx.win, key_hook, &vars);
	mlx_hook(mlx.win, 17, 0, close_window, &vars);
	mlx_loop(mlx.mlx);
	free(vars.player);
	close(fd);
}
