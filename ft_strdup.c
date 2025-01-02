/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:04:56 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/02 09:38:21 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s1)
{
	char	*s;

	s = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (s == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	return (s);
}
