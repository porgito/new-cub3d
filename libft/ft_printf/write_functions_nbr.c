/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_functions_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:56:58 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/12 15:50:00 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_count(int n, int *count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
	}
	else
	{
		if (n < 0)
		{
			n = n * -1;
			ft_putchar_fd('-', 1);
			*count += 1;
		}
		if (n > 9)
			ft_putnbr_count(n / 10, count);
		ft_putchar_fd(n % 10 + '0', 1);
		*count += 1;
	}
}

void	ft_putnbr_unsigned_fd(unsigned int n, int fd, int *count)
{
	if (n > 9)
		ft_putnbr_unsigned_fd(n / 10, fd, count);
	ft_putchar_fd(n % 10 + '0', fd);
	*count += 1;
}
