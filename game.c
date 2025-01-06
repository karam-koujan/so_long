/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:43:15 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/06 09:17:01 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*player(char	**map, t_vars *vars)
{
	t_player	*player;
	void		*component;
	int			*corr;

	component = mlx_xpm_file_to_image(vars->libx.mlx, "./textures/character.xpm", &vars->map_metadata.width, &vars->map_metadata.height);
	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	corr = get_component_corr(map, 'P');
	player->player_component = component;
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
	{
		if (map[vars->map_metadata.y - 1][vars->map_metadata.x] == '1')
			return ;
		vars->map_metadata.y--;
		(*player->y)--;
		component_render_pos(vars->libx, map, player->player_component, \
		vars->map_metadata);
		vars->map_metadata.y++;
		component_render_pos(vars->libx, map, bg, vars->map_metadata);
		vars->map_metadata.y--;
	}
	if (keycode == 0)
	{
		if (map[vars->map_metadata.y + 1][vars->map_metadata.x] == '1')
			return ;
		vars->map_metadata.y++;
		(*player->y)++;
		component_render_pos(vars->libx, map, player->player_component, \
		vars->map_metadata);
		vars->map_metadata.y--;
		component_render_pos(vars->libx, map, bg, vars->map_metadata);
		vars->map_metadata.y++;
	}
	if (map[vars->map_metadata.y][vars->map_metadata.x] == 'C')
		player->coins--;
}

void	player_h_move(char	**map, t_player *player, int keycode, t_vars *vars)
{
	void	*bg;

	vars->map_metadata.x = *player->x;
	vars->map_metadata.y = *player->y;
	bg = mlx_xpm_file_to_image(vars->libx.mlx, "./textures/road.xpm", \
	&vars->map_metadata.width, &vars->map_metadata.height);
	if (keycode == 1)
	{
		if (map[vars->map_metadata.y][vars->map_metadata.x - 1] == '1')
			return ;
		vars->map_metadata.x--;
		(*player->x)--;
		component_render_pos(vars->libx, map, player->player_component, \
		vars->map_metadata);
		vars->map_metadata.x++;
		component_render_pos(vars->libx, map, bg, vars->map_metadata);
		vars->map_metadata.x--;
	}
	if (keycode == 2)
	{
		if (map[vars->map_metadata.y][vars->map_metadata.x + 1] == '1')
			return ;
		vars->map_metadata.x++;
		(*player->x)++;
		component_render_pos(vars->libx, map, player->player_component, \
		vars->map_metadata);
		vars->map_metadata.x--;
		component_render_pos(vars->libx, map, bg, vars->map_metadata);
		vars->map_metadata.x++;
	}
	if (map[vars->map_metadata.y][vars->map_metadata.x] == 'C')
		player->coins--;
}
