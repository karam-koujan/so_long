/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:43:15 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/13 09:52:30 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*player_init(char **map)
{
	t_player	*player;
	int			*corr;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	corr = get_component_corr(map, 'P');
	player->x = corr;
	player->y = corr + 1;
	player->steps_count = 0;
	player->coins = count_components(map, 'C');
	return (player);
}

t_player	*player(char	**map, t_vars *vars)
{
	t_player	*player;
	char		*abs;
	char		*p_path;

	abs = vars->abs;
	player = player_init(map);
	p_path = ft_strjoin(abs, "textures/character.xpm");
	player->player_component = mlx_xpm_file_to_image(vars->libx.mlx, p_path, \
	&vars->map_metadata.width, &vars->map_metadata.height);
	free(p_path);
	p_path = ft_strjoin(vars->abs, "textures/characterflip.xpm");
	player->player_c_flip = mlx_xpm_file_to_image(vars->libx.mlx, p_path, \
	&vars->map_metadata.width, &vars->map_metadata.height);
	free(p_path);
	return (player);
}

void	player_v_move(char	**map, t_player *player, int keycode, t_vars *vars)
{
	void	*bg;
	char	*abs;
	char	*path;

	vars->map_metadata.x = *player->x;
	vars->map_metadata.y = *player->y;
	abs = vars->abs;
	path = ft_strjoin(abs, "textures/road.xpm");
	bg = mlx_xpm_file_to_image(vars->libx.mlx, path, \
	&vars->map_metadata.width, &vars->map_metadata.height);
	if (keycode == 13)
		move_up(map, bg, player, vars);
	if (keycode == 0)
		move_down(map, bg, player, vars);
	free(path);
	mlx_destroy_image(vars->libx.mlx, bg);
}

void	player_h_move(char	**map, t_player *player, int keycode, t_vars *vars)
{
	void	*bg;
	char	*abs;
	char	*path;

	vars->map_metadata.x = *player->x;
	vars->map_metadata.y = *player->y;
	abs = vars->abs;
	path = ft_strjoin(abs, "textures/road.xpm");
	bg = mlx_xpm_file_to_image(vars->libx.mlx, path, \
	&vars->map_metadata.width, &vars->map_metadata.height);
	if (keycode == 1)
		move_left(map, bg, player, vars);
	if (keycode == 2)
		move_right(map, bg, player, vars);
	free(path);
	mlx_destroy_image(vars->libx.mlx, bg);
}
