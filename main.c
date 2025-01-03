/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:46:50 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/03 15:36:48 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void f()
{
	system("leaks so_long");
}


int	main(int ac, char **av)
{
	char	*file_path;
	char	**map;
	int		fd;
	t_data	mlx;

	if (ac == 1 || ac > 2)
	{
		return (1);
	}
	mlx.mlx = mlx_init();
	file_path = av[1];
	fd = open(file_path, O_RDONLY, 0777);
	map = read_map(fd, file_path);
	char **c = copy_map(map);
	if (check_map(map))
	{
		mlx.height = 100 * count_rows(map);
		mlx.width = 100 * ft_strlen(map[0]);
		mlx.win = mlx_new_window(mlx.mlx, mlx.width, \
									mlx.height, av[0]);
		map_render(c, mlx);
	}
	free_arr(map, count_rows(map));
	mlx_loop(mlx.mlx);
	close(fd);
	atexit(f);
}
