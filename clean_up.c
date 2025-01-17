/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:43:54 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/17 11:46:28 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_up(t_vars *vars)
{
	if (vars->map)
		free_arr(vars->map, count_rows(vars->map));
	if (vars->abs)
		free(vars->abs);
	mlx_destroy_image(vars->libx.mlx, vars->player->player_component);
	if (vars->player && vars->player->x)
		free(vars->player->x);
	if (vars->player && vars->player->player_component)
		mlx_destroy_image(vars->libx.mlx, vars->player->player_component);
	if (vars->player && vars->player->player_c_flip)
		mlx_destroy_image(vars->libx.mlx, vars->player->player_c_flip);
	free(vars->player);
	mlx_clear_window(vars->libx.mlx, vars->libx.win);
}

void	clean_movement(t_vars *vars, char *num, char **numbers)
{
	int	i;

	i = -1;
	while (++i < 10)
		free(numbers[i]);
	free(num);
	clean_up(vars);
}