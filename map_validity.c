/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:20:28 by kkoujan           #+#    #+#             */
/*   Updated: 2024/12/31 21:08:33 by kkoujan          ###   ########.fr       */
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
		if (map[0][i] != '1' || map[0][i] != '1')
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

int	check_map(char **map)
{

	if (!is_rectangular(map))
		return (1);
	if (!check_walls(map))
		ft_printf("make walls!!");
	return 0;
}