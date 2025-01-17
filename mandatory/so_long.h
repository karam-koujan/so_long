/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:55:26 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/17 19:09:42 by kkoujan          ###   ########.fr       */
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
	char	*abs;
	int		x;
	int		y;
}				t_map;

typedef struct s_vars
{
	t_data				libx;
	t_map				map_metadata;
	char				**map;	
	struct s_player		*player;
	char				*abs;
}				t_vars;

typedef struct s_player
{
	void	*player_component;
	void	*player_c_flip;
	int		*x;
	int		*y;
	int		steps_count;
	int		coins;
}				t_player;
char		**read_map(int fd, char *file_path);
char		*get_next_line(int fd);
int			ft_printf(const char *format, ...);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
int			calculate_rows(char	*file_path);
int			check_map(char **map);
char		**copy_map(char **map);
void		free_arr(char **arr, int i);
char		*ft_strdup(const char *s1);
int			count_components(char **map, char c);
int			count_rows(char **map);
int			calculate_cols(char *row);
int			*get_component_corr(char **map, char c);
int			is_rectangular(char **map);
int			check_walls(char **map);
int			check_elements(char **map);
int			dfs(char **map, int x, int y, int rows);
int			is_path_valid(char **map);
void		map_render(char **map, t_vars *vars);
void		component_render_pos(t_data mlx, char **map, void *img, \
t_map map_metadata);
t_player	*player(char	**map, t_vars *vars);
void		player_v_move(char	**map, t_player *player, \
int keycode, t_vars *vars);
void		player_h_move(char	**map, t_player *player, \
int keycode, t_vars *vars);
char		*ft_itoa(int n);
void		init_numbers(char	**numbers, t_vars *vars);
void		move_up(char **map, void *bg, t_player *player, t_vars *vars);
void		move_down(char **map, void *bg, t_player *player, t_vars *vars);
void		move_left(char **map, void *bg, t_player *player, t_vars *vars);
void		move_right(char **map, void *bg, t_player *player, t_vars *vars);
char		**ft_split(char const *s, char c);
int			check_path(char *path);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*absolute_path(char *path);
char		*ft_strjoin(char const *s1, char const *s2);
void		clean_up(t_vars *vars);
void		count(t_player *player);
#endif