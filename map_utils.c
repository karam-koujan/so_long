/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:15:33 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/02 14:41:40 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_arr(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
	arr = NULL;
}

char	**copy_map(char **map)
{
	char	**new_map;
	int		i;
	int		rows;

	i = 0;
	rows = 0;
	while (map[rows] != NULL)
		rows++;
	new_map = malloc((rows + 1) * sizeof(char *));
	if (!new_map)
		return (NULL);
	while (i < rows)
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

int	count_rows(char **map)
{
	int	rows;

	rows = 0;
	while (map[rows] != NULL)
		rows++;
	return (rows);
}

int	count_components(char **map, char c)
{
	int		count;
	int		rows;
	size_t	i;

	i = 0;
	rows = 0;
	count = 0;
	while (map[rows] != NULL)
	{
		i = 0;
		while (i < ft_strlen(map[rows]))
		{
			if (map[rows][i] == c)
				count++;
			i++;
		}
		rows++;
	}
	return (count);
}

int	*get_component_corr(char **map, char c)
{
	int		*res;
	int		rows;
	size_t	i;

	rows = 0;
	res = (int *)malloc(2 * sizeof(int));
	if (!res)
		return (NULL);
	while (map[rows] != NULL)
	{
		i = 0;
		while (i < ft_strlen(map[rows]))
		{
			if (map[rows][i] == c)
			{
				res[0] = i;
				res[1] = rows;
			}
			i++;
		}
		rows++;
	}
	return (res);
}