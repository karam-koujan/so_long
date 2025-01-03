/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:55:26 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/03 15:32:56 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}				t_data;
typedef struct s_map
{
	int		width;
	int		height;
	char	component;
}				t_map;
char	**read_map(int fd, char *file_path);
char	*get_next_line(int fd);
int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		calculate_rows(char	*file_path);
int		check_map(char **map);
char	**copy_map(char **map);
void	free_arr(char **arr, int i);
char	*ft_strdup(const char *s1);
int		count_components(char **map, char c);
int		count_rows(char **map);
int		calculate_cols(char *row);
int		*get_component_corr(char **map, char c);
int		is_rectangular(char **map);
int		check_walls(char **map);
int		check_elements(char **map);
int		dfs(char **map, int x, int y, int rows);
int		is_path_valid(char **map);
int		map_render(char **map, t_data mlx);
#endif