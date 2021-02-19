/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:36:48 by azouzoul          #+#    #+#             */
/*   Updated: 2021/01/23 17:04:20 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_elem;
	t_list	*next_elem;

	next_elem = *lst;
	if (!next_elem)
		return ;
	while (next_elem)
	{
		current_elem = next_elem;
		next_elem = current_elem->next;
		ft_lstdelone(current_elem, del);
	}
	*lst = NULL;
}
