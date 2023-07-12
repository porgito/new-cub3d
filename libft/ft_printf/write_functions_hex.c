/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_functions_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:26:40 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/12 15:50:00 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_hex_unsigned(unsigned long nb, char *base, int *count)
{
	unsigned long	lenght;
	unsigned long	a;

	a = nb;
	lenght = ft_strlen(base);
	if (a >= lenght)
		ft_putnbr_hex_unsigned(a / lenght, base, count);
	ft_putchar_count(base[a % lenght], count);
}

void	ft_putvoid_addrr(unsigned long nb, int *count)
{
	if (nb == 0)
		ft_putstr_count("0x0", count);
	else
	{
		ft_putstr_count("0x", count);
		ft_putnbr_hex_unsigned(nb, "0123456789abcdef", count);
	}
}
