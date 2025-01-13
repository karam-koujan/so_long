/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:04:25 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/13 09:25:38 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_numbers(char	**numbers, t_vars *vars)
{
	numbers[0] = ft_strjoin(vars->abs, "textures/0.xpm");
	numbers[1] = ft_strjoin(vars->abs, "textures/1.xpm");
	numbers[2] = ft_strjoin(vars->abs, "textures/2.xpm");
	numbers[3] = ft_strjoin(vars->abs, "textures/3.xpm");
	numbers[4] = ft_strjoin(vars->abs, "textures/4.xpm");
	numbers[5] = ft_strjoin(vars->abs, "textures/5.xpm");
	numbers[6] = ft_strjoin(vars->abs, "textures/6.xpm");
	numbers[7] = ft_strjoin(vars->abs, "textures/7.xpm");
	numbers[8] = ft_strjoin(vars->abs, "textures/8.xpm");
	numbers[9] = ft_strjoin(vars->abs, "textures/9.xpm");
}

int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

int	check_path(char *path)
{
	char	**path_arr;
	char	*format;

	path_arr = ft_split(path, '.');
	if (arr_len(path_arr) < 2)
	{
		free_arr(path_arr, arr_len(path_arr));
		return (0);
	}
	format = path_arr[arr_len(path_arr) - 1];
	if (ft_strncmp(format, "ber", 3) != 0)
	{
		free_arr(path_arr, arr_len(path_arr));
		return (0);
	}
	free_arr(path_arr, arr_len(path_arr));
	return (1);
}

char	*absolute_path(char *path)
{
	char	**path_arr;
	char	*res_path;
	int		len;

	path_arr = ft_split(path, '/');
	len = arr_len(path_arr);
	res_path = ft_substr(path, 0, ft_strlen(path) - \
	ft_strlen(path_arr[len - 1]));
	free_arr(path_arr, len - 1);
	return (res_path);
}

void	clean_up(t_vars *vars)
{
	free_arr(vars->map, count_rows(vars->map));
	free(vars->abs);
	mlx_destroy_image(vars->libx.mlx, vars->player->player_component);
	free(vars->player->x);
	free(vars->player->y);
	mlx_destroy_image(vars->libx.mlx, vars->player->player_c_flip);
	mlx_clear_window(vars->libx.mlx, vars->libx.win);
	free(vars->player);
}
