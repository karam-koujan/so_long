/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:52:28 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/17 15:20:18 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H 
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putunbr_base(unsigned int n, char *base);
int		ft_putaddress(void *p);
size_t	ft_strlen(const char *s);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_putchar(char c);
char	*ft_strchr(const char *s, int c);

#endif