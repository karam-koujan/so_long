/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:25:49 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/17 11:56:36 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(char **map, void *bg, t_player *player, t_vars *vars)
{
	if (map[vars->map_metadata.y][vars->map_metadata.x - 1] == 'N')
		return (clean_up(vars), mlx_destroy_image(vars->libx.mlx, bg), exit(0));
	if (map[vars->map_metadata.y][vars->map_metadata.x - 1] == 'E')
	{
		if (player->coins)
			return ;
		return (clean_up(vars), mlx_destroy_image(vars->libx.mlx, bg), exit(0));
	}
	if (map[vars->map_metadata.y][vars->map_metadata.x - 1] == '1')
		return ;
	count(player, vars);
	vars->map_metadata.x--;
	(*player->x)--;
	if (map[vars->map_metadata.y][vars->map_metadata.x] == 'C')
	{
		map[vars->map_metadata.y][vars->map_metadata.x] = '0';
		component_render_pos(vars->libx, map, bg, vars->map_metadata);
		player->coins--;
	}
	component_render_pos(vars->libx, map, player->player_c_flip, \
	vars->map_metadata);
	vars->map_metadata.x++;
	component_render_pos(vars->libx, map, bg, vars->map_metadata);
	vars->map_metadata.x--;
}

void	move_right(char **map, void *bg, t_player *player, t_vars *vars)
{
	if (map[vars->map_metadata.y][vars->map_metadata.x + 1] == 'N')
		return (clean_up(vars), mlx_destroy_image(vars->libx.mlx, bg), exit(0));
	if (map[vars->map_metadata.y][vars->map_metadata.x + 1] == 'E')
	{
		if (player->coins)
			return ;
		return (clean_up(vars), mlx_destroy_image(vars->libx.mlx, bg), exit(0));
	}
	if (map[vars->map_metadata.y][vars->map_metadata.x + 1] == '1')
		return ;
	count(player, vars);
	vars->map_metadata.x++;
	(*player->x)++;
	if (map[vars->map_metadata.y][vars->map_metadata.x] == 'C')
	{
		map[vars->map_metadata.y][vars->map_metadata.x] = '0';
		component_render_pos(vars->libx, map, bg, vars->map_metadata);
		player->coins--;
	}
	component_render_pos(vars->libx, map, player->player_component, \
	vars->map_metadata);
	vars->map_metadata.x--;
	component_render_pos(vars->libx, map, bg, vars->map_metadata);
	vars->map_metadata.x++;
}

void	move_up(char **map, void *bg, t_player *player, t_vars *vars)
{
	if (map[vars->map_metadata.y - 1][vars->map_metadata.x] == 'N')
		return (clean_up(vars), mlx_destroy_image(vars->libx.mlx, bg), exit(0));
	if (map[vars->map_metadata.y - 1][vars->map_metadata.x] == 'E')
	{
		if (player->coins)
			return ;
		return (clean_up(vars), mlx_destroy_image(vars->libx.mlx, bg), exit(0));
	}
	if (map[vars->map_metadata.y - 1][vars->map_metadata.x] == '1')
		return ;
	count(player, vars);
	vars->map_metadata.y--;
	(*player->y)--;
	if (map[vars->map_metadata.y][vars->map_metadata.x] == 'C')
	{
		map[vars->map_metadata.y][vars->map_metadata.x] = '0';
		component_render_pos(vars->libx, map, bg, vars->map_metadata);
		player->coins--;
	}
	component_render_pos(vars->libx, map, player->player_component, \
	vars->map_metadata);
	vars->map_metadata.y++;
	component_render_pos(vars->libx, map, bg, vars->map_metadata);
	vars->map_metadata.y--;
}

void	move_down(char **map, void *bg, t_player *player, t_vars *vars)
{
	if (map[vars->map_metadata.y + 1][vars->map_metadata.x] == 'N')
		return (clean_up(vars), mlx_destroy_image(vars->libx.mlx, bg), exit(0));
	if (map[vars->map_metadata.y + 1][vars->map_metadata.x] == 'E')
	{
		if (player->coins)
			return ;
		return (clean_up(vars), mlx_destroy_image(vars->libx.mlx, bg), exit(0));
	}
	if (map[vars->map_metadata.y + 1][vars->map_metadata.x] == '1')
		return ;
	count(player, vars);
	vars->map_metadata.y++;
	(*player->y)++;
	if (map[vars->map_metadata.y][vars->map_metadata.x] == 'C')
	{
		map[vars->map_metadata.y][vars->map_metadata.x] = '0';
		component_render_pos(vars->libx, map, bg, vars->map_metadata);
		player->coins--;
	}
	component_render_pos(vars->libx, map, player->player_component, \
	vars->map_metadata);
	vars->map_metadata.y--;
	component_render_pos(vars->libx, map, bg, vars->map_metadata);
	vars->map_metadata.y++;
}

void	count(t_player *player, t_vars *vars)
{
	player->steps_count++;
	ft_printf("%i\n", player->steps_count);
	movement_count(player->steps_count, vars);
}
