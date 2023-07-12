/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:01:25 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/12 15:50:00 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char			*s;
	char			*d;
	unsigned int	i;

	i = -1;
	s = (char *)src;
	d = (char *)dst;
	if (src != 0 || dst != 0)
	{
		if (d < s)
		{
			while (++i < n)
				d[i] = s[i];
		}
		else
		{
			while (n > 0)
			{
				d[n - 1] = s[n - 1];
				n--;
			}
		}
	}
	return (dst);
}
