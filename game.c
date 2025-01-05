/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:43:15 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/05 13:32:33 by kkoujan          ###   ########.fr       */
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
	(void)map;
	vars->map_metadata.x = *player->x;
	vars->map_metadata.y = *player->y;
	vars->map_metadata.height = 60;
	vars->map_metadata.width = 60;
	if (keycode == 13)
	{
		vars->map_metadata.y--;
		(*player->y)--;
		component_render_pos(vars->libx, player->player_component, \
		vars->map_metadata);
		return ;
	}
	if (keycode == 0)
	{
		vars->map_metadata.y++;
		(*player->y)++;
		component_render_pos(vars->libx, player->player_component, \
		vars->map_metadata);
		return ;
	}
}

void	player_h_move(char	**map, t_player *player, int keycode, t_vars *vars)
{
	(void)map;
	vars->map_metadata.x = *player->x;
	vars->map_metadata.y = *player->y;
	if (keycode == 1)
	{
		vars->map_metadata.x--;
		(*player->x)--;
		component_render_pos(vars->libx, player->player_component, \
		vars->map_metadata);
		return ;
	}
	if (keycode == 2)
	{
		vars->map_metadata.x++;
		(*player->x)++;
		component_render_pos(vars->libx, player->player_component, \
		vars->map_metadata);
		return ;
	}
}
