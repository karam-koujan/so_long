/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:40:02 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/17 14:48:56 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_putaddress_base(unsigned long n, char *base)
{
	char			r;
	unsigned int	len;
	int				count;

	len = ft_strlen(base);
	count = 0;
	if (n >= len)
	{
		count += ft_putaddress_base(n / len, base);
	}
	r = base[n % len];
	write(1, &r, 1);
	count++;
	return (count);
}

int	ft_putaddress(void *p)
{
	unsigned long	address;

	address = (unsigned long)p;
	return (ft_putstr("0x") + \
	ft_putaddress_base(address, "0123456789abcdef"));
}
