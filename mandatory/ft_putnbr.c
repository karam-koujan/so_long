/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:07:36 by kkoujan           #+#    #+#             */
/*   Updated: 2024/11/19 20:15:57 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char		r;
	long		nbr;
	int			count;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		count++;
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		count += ft_putnbr(nbr / 10);
	}
	r = nbr % 10 + '0';
	write(1, &r, 1);
	count++;
	return (count);
}
