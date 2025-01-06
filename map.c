/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:34:54 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/05 14:02:12 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	calculate_cols(char *row)
{
	int	cols;

	cols = ft_strlen(row);
	if (!cols)
		return (cols);
	if (row[cols - 1] == '\n')
	{
		cols--;
	}
	return (cols);
}

int	calculate_rows(char	*file_path)
{
	char	*row_line;
	int		rows;
	int		fd;

	fd = open(file_path, O_RDONLY, 0777);
	row_line = get_next_line(fd);
	rows = 0;
	while (row_line)
	{
		free(row_line);
		rows++;
		row_line = get_next_line(fd);
	}
	free(row_line);
	close(fd);
	return (rows);
}

int	check_map(char **map)
{
	return (is_rectangular(map) && check_walls(map) && check_elements(map) \
				&& is_path_valid(map));
}

char	**read_map(int fd, char *file_path)
{
	char	**map;
	int		i;
	char	*row_line;

	i = 0;
	map = (char **)malloc((calculate_rows(file_path) + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	row_line = get_next_line(fd);
	while (row_line)
	{
		map[i] = (char *)malloc(calculate_cols(row_line) * sizeof(char));
		if (!map)
		{
			free_arr(map, i - 1);
			return (NULL);
		}
		ft_strlcpy(map[i], row_line, calculate_cols(row_line) + 1);
		free(row_line);
		row_line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (free(row_line), map);
}
