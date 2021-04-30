/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:13:01 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/30 16:13:03 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_node_pos(t_list *head, t_list *node)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = head;
	while (tmp->content != node->content)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_largest(t_heads *heads)
{
	int		i;
	int		mem;
	t_list	*tmp1;
	t_list	*tmp2;

	i = 0;
	mem = -2147483648;
	tmp1 = heads->head_a;
	tmp2 = heads->head_a;
	while (tmp1)
	{
		if (mem <= tmp1->content)
			mem = tmp1->content;
		tmp1 = tmp1->next;
	}
	while (tmp2 && tmp2->content != mem)
	{
		i++;
		tmp2 = tmp2->next;
	}
	return (i + 1);
}

int	ft_findpos(t_heads *heads, t_list *node)
{
	int		i;
	int		mem;
	t_list	*tmp1;
	t_list	*tmp2;

	i = 0;
	mem = 2147483647;
	tmp1 = heads->head_a;
	tmp2 = heads->head_a;
	while (tmp1)
	{
		if (tmp1->content > node->content)
			if (mem >= tmp1->content)
				mem = tmp1->content;
		tmp1 = tmp1->next;
	}
	while (tmp2 && tmp2->content != mem)
	{
		i++;
		tmp2 = tmp2->next;
	}
	if (tmp2)
		return (i);
	else
		return (ft_largest(heads));
}

int	ft_push_convenience(t_heads *heads, t_list *node)
{
	t_list	*tmp;
	int		i;
	int		j;
	int		pb;
	int		pa;

	pb = 0;
	pa = 0;
	i = 0;
	j = 0;
	i = ft_node_pos(heads->head_b, node);
	if (i <= ((ft_lstsize(heads->head_b)) / 2))
		pb = i;
	else
		pb = (ft_lstsize(heads->head_b)) - i;
	tmp = heads->head_a;
	i = ft_findpos(heads, node);
	if (i <= ((ft_lstsize(heads->head_a)) / 2))
		pa = i;
	else
		pa = (ft_lstsize(heads->head_a)) - i;
	node->pa = pa;
	node->pb = pb;
	return (pa + pb);
}

int	ft_position(t_list *lst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->content > tmp->next->content)
			return (i + 1);
		i++;
		tmp = tmp->next;
		if (tmp->next == NULL)
			break ;
	}
	return (0);
}
