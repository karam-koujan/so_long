/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:17:01 by kkoujan           #+#    #+#             */
/*   Updated: 2024/11/15 12:57:27 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr_base(unsigned int n, char *base)
{
	char			r;
	unsigned int	len;
	int				count;

	count = 0;
	len = ft_strlen(base);
	if (n >= len)
	{
		count += ft_putunbr_base(n / len, base);
	}
	r = base[n % len];
	write(1, &r, 1);
	count++;
	return (count);
}
