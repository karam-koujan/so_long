/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:11:18 by kkoujan           #+#    #+#             */
/*   Updated: 2024/12/31 16:50:44 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	c = (char)c;
	if (s == NULL)
		return (0);
	while (*p)
	{
		if (*p == c)
		{
			return (p);
		}
		p++;
	}
	if (*p == c)
	{
		return (p);
	}
	return (0);
}