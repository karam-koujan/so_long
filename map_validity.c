/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:20:28 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/02 12:47:27 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char **map)
{
	size_t	rows;
	size_t	cols;

	cols = 0;
	rows = 0;
	while (map[rows] != NULL)
	{
		if (rows != 0 && (ft_strlen(map[rows]) != cols))
			return (0);
		cols = ft_strlen(map[rows]);
		rows++;
	}
	if (cols == 0 && rows == 0)
		return (0);
	return (1);
}

int	check_walls(char **map)
{
	size_t	rows;
	size_t	cols;
	size_t	i;

	cols = ft_strlen(map[0]);
	rows = 0;
	i = 0;
	while (map[rows] != NULL)
		rows++;
	while (i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_elements(char **map)
{
	int		exit;
	int		collectible;
	int		s_pos;
	size_t	rows;
	size_t	cols;

	exit = 0;
	collectible = 0;
	s_pos = 0;
	rows = 0;
	while (map[rows])
	{
		cols = 0;
		while (cols < ft_strlen(map[rows]))
		{
			if (map[rows][cols] == 'E')
				exit++;
			if (map[rows][cols] == 'C')
				collectible++;
			if (map[rows][cols] == 'P')
				s_pos++;
			cols++;
		}
		rows++;
	}
	return (1 && !(exit != 1 || collectible == 0 || s_pos != 1));
}

int	dfs(char **map, int x, int y, int rows)
{
	int	cols;
	int	collectible;
	int	result;

	result = 0;
	cols = ft_strlen(map[0]);
	collectible = 0;
	if (x < 0 || y < 0 || x >= cols || y >= rows || map[y][x] == '1' || map[y][x] == 'V')
	{
		return (0);
	}
	if (map[y][x] == 'E')
	{
		return ( 1);
	}
	if (map[y][x] == 'C')
		collectible++;
	map[y][x] = 'V';
	result = dfs(map, x + 1, y, rows) + dfs(map, x - 1, y, rows) + dfs(map, x , y + 1, rows) + dfs(map, x, y - 1, rows);
	return (collectible + result );
}

int	is_path_valid(char **map)
{
	char		**map_copy;
	int			rows;
	int			collectible;
	int			res;

	rows = count_rows(map);
	collectible = count_components(map,'C');
	map_copy = copy_map(map);
	if (!map_copy)
		return (0);
	res = dfs(map, get_component_corr(map, 'P')[0], \
				get_component_corr(map, 'P')[1], rows - 1);
	free_arr(map_copy, rows - 1);
	return (res >= collectible + 1);
}

int	check_map(char **map)
{
	return (is_rectangular(map) || check_walls(map) || check_elements(map) \
				|| is_path_valid(map));
}
