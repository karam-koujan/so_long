/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:43:15 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/08 11:50:49 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*player(char	**map, t_vars *vars)
{
	t_player	*player;
	void		*component;
	int			*corr;
	t_data		libx;

	libx = vars->libx;
	component = mlx_xpm_file_to_image(libx.mlx, "./textures/character.xpm", \
	&vars->map_metadata.width, &vars->map_metadata.height);
	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	corr = get_component_corr(map, 'P');
	player->player_component = component;
	component = mlx_xpm_file_to_image(libx.mlx, "./textures/characterflip.xpm", \
	&vars->map_metadata.width, &vars->map_metadata.height);
	player->player_c_flip = component;
	player->x = corr;
	player->y = corr + 1;
	player->steps_count = 0;
	player->coins = count_components(map, 'C');
	return (player);
}

void	player_v_move(char	**map, t_player *player, int keycode, t_vars *vars)
{
	void	*bg;

	vars->map_metadata.x = *player->x;
	vars->map_metadata.y = *player->y;
	bg = mlx_xpm_file_to_image(vars->libx.mlx, "./textures/road.xpm", \
	&vars->map_metadata.width, &vars->map_metadata.height);
	if (keycode == 13)
		move_up(map, bg, player, vars);
	if (keycode == 0)
		move_down(map, bg, player, vars);
	mlx_destroy_image(vars->libx.mlx, bg);
}

void	player_h_move(char	**map, t_player *player, int keycode, t_vars *vars)
{
	void	*bg;

	vars->map_metadata.x = *player->x;
	vars->map_metadata.y = *player->y;
	bg = mlx_xpm_file_to_image(vars->libx.mlx, "./textures/road.xpm", \
	&vars->map_metadata.width, &vars->map_metadata.height);
	if (keycode == 1)
		move_left(map, bg, player, vars);
	if (keycode == 2)
		move_right(map, bg, player, vars);
	mlx_destroy_image(vars->libx.mlx, bg);
}
