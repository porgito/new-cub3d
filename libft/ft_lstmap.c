/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:34:55 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/12 15:50:00 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tab;
	char	*str;

	tab = NULL;
	if (!del || !f)
		return (NULL);
	while (lst != NULL)
	{
		str = (*f)(lst->content);
		new = ft_lstnew(str);
		if (!new)
		{
			del(str);
			ft_lstclear(&tab, (*del));
			return (NULL);
		}
		ft_lstadd_back(&tab, new);
		lst = lst->next;
	}
	return (tab);
}
