/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:46:50 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/02 15:39:03 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	*file_path;
	char	**map;
	int		fd;

	if (ac == 1 || ac > 2)
	{
		return (1);
	}
	file_path = av[1];
	fd = open(file_path, O_RDONLY, 0777);
	ft_printf("fd %i",fd);
	map = read_map(fd,file_path);
	int d = check_map(map);
	ft_printf("%i",d);
	close(fd);

}
