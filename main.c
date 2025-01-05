/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:46:50 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/05 11:49:38 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void f()
{
	system("leaks so_long");
}

int	key_hook(int keycode, t_vars *vars)
{
	t_map 	map_metadata;
	void	*component;
	map_metadata.component = 'P';
	component = mlx_xpm_file_to_image(vars->libx.mlx, "./textures/character.xpm", \
									&map_metadata.width, &map_metadata.height);
	ft_printf("%i\n",keycode);
	if (keycode == 53)
	{
		f();
		exit(0);
		return (0);
	}
	if (keycode == 13)
	{
		map_metadata.x = vars->player_corr[0];
		map_metadata.y= vars->player_corr[1] - 1;
		ft_printf("%i\n",map_metadata.y);
		vars->player_corr[1] = map_metadata.y;
		component_render_pos(vars->libx, component, map_metadata);
		return (0);
	}
	if (keycode == 0)
	{
		map_metadata.x = vars->player_corr[0];
		map_metadata.y= vars->player_corr[1] + 1;
		ft_printf("%i\n",map_metadata.y);
		vars->player_corr[1] = map_metadata.y;
		component_render_pos(vars->libx, component, map_metadata);
		return (0);
	}
	if (keycode == 1)
	{
		map_metadata.x = vars->player_corr[0] - 1;
		map_metadata.y= vars->player_corr[1];
		ft_printf("%i\n",map_metadata.y);
		vars->player_corr[0] = map_metadata.x;
		component_render_pos(vars->libx, component, map_metadata);
		return (0);
	}
	if (keycode == 2)
	{
		map_metadata.x = vars->player_corr[0] + 1;
		map_metadata.y= vars->player_corr[1];
		ft_printf("%i\n",map_metadata.y);
		vars->player_corr[0] = map_metadata.x;
		component_render_pos(vars->libx, component, map_metadata);
		return (0);
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
	vars.player_corr = get_component_corr(vars.map,'P');
	free_arr(map, count_rows(map));
	mlx_key_hook(mlx.win, key_hook, &vars);
	mlx_hook(mlx.win, 17, 0, close_window, &vars);
	mlx_loop(mlx.mlx);
	close(fd);
}
