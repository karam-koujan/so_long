/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:46:50 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/02 12:49:40 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	*file_path;
	char	**map;

	if (ac == 1 || ac > 2)
	{
		return (1);
	}
	file_path = av[1];
	map = read_map(file_path);
	ft_printf("%i\n",check_map(map));
}
