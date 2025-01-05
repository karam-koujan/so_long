/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:46:50 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/05 13:34:52 by kkoujan          ###   ########.fr       */
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
	player_v_move(vars->map, vars->player, keycode, vars);
	player_h_move(vars->map, vars->player, keycode, vars);

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
	fd = open(av[1], O_RDONLY, 0777);
	map = read_map(fd, av[1]);
	char **c_map = copy_map(map);
	if (check_map(map))
	{
		mlx.height = 60 * count_rows(map);
		mlx.width = 60 * ft_strlen(map[0]);
		mlx.win = mlx_new_window(mlx.mlx, mlx.width, \
									mlx.height, av[0]);
		map_render(c_map, mlx);
	}
	vars.libx = mlx;
	vars.map = c_map;
	vars.player = player(c_map, &vars);
	free_arr(map, count_rows(map));
	mlx_key_hook(mlx.win, key_hook, &vars);
	mlx_hook(mlx.win, 17, 0, close_window, &vars);
	mlx_loop(mlx.mlx);
	close(fd);
}
