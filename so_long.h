/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:55:26 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/02 12:46:01 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

char	**read_map(char *path);
char	*get_next_line(int fd);
int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		calculate_rows(int fd);
int		check_map(char **map);
char	**copy_map(char **map);
void	free_arr(char **arr, int i);
char	*ft_strdup(const char *s1);
int		count_components(char **map, char c);
int		count_rows(char **map);
int		*get_component_corr(char **map, char c);
#endif