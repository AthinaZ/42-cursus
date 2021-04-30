/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:12:06 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/30 16:12:08 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **head)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	if ((*head) == NULL || (*head)->next == NULL)
		return ;
	node1 = *head;
	node2 = (*head)->next;
	if (node2->next != NULL)
	{
		node3 = node2;
		node3 = node3->next;
		node3->prev = node1;
	}
	node1->next = node2->next;
	node2->next = node1;
	node1->prev = node2;
	*head = node2;
	node2->prev = NULL;
}

void	ft_push(t_list **dst, t_list **src)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*src == NULL)
		return ;
	tmp1 = *src;
	if ((*src)->next != NULL)
	{
		*src = (*src)->next;
		(*src)->prev = NULL;
	}
	else
		(*src) = NULL;
	tmp2 = ft_lstnew(tmp1->content);
	free(tmp1);
	if (*dst == NULL)
	{
		*dst = tmp2;
		return ;
	}
	tmp2->next = *dst;
	(*dst)->prev = tmp2;
	(*dst) = (*dst)->prev;
}

void 	ft_rotate(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp1;

	if ((*head) == NULL || (*head)->next == NULL)
		return ;
	tmp1 = *head;
	tmp = ft_lstnew((*head)->content);
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(tmp1);
	tmp1 = *head;
	tmp1 = ft_lstlast(tmp1);
	tmp1->next = tmp;
	tmp->prev = tmp1;
}

void 	ft_reverse_r(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp1;
	t_list	*tmp2;

	if ((*head) == NULL || (*head)->next == NULL)
		return ;
	tmp1 = *head;
	while (tmp1->next)
		tmp1 = tmp1->next;
	tmp2 = tmp1->prev;
	tmp2->next = NULL;
	tmp = ft_lstnew(tmp1->content);
	free(tmp1);
	tmp->next = *head;
	(*head)->prev = tmp;
	*head = (*head)->prev;
}

void	ft_printalo(t_heads *heads, int flag)
{
	t_list	*tmp;
	t_list	*tmp1;

	if (flag == 1)
	{
		tmp = heads->head_a;
		tmp1 = heads->head_b;
		write(1, "\n--------------------------------\n", 34);
		write(1, "stack A          stack B\n\n", 26);
		ft_printalo2(tmp, tmp1);
		write(1, "--------------------------------\n\n", 34);
	}
}
