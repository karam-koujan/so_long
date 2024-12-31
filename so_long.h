/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:55:26 by kkoujan           #+#    #+#             */
/*   Updated: 2024/12/31 20:25:24 by kkoujan          ###   ########.fr       */
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
int	calculate_rows(int fd);
int	check_map(char **map);

#endif