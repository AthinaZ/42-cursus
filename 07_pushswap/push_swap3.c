/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:12:42 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/30 16:12:43 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_subsequence(t_list *lst)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		i;

	tmp1 = lst->next;
	tmp2 = lst;
	i = 0;
	while (tmp2->next)
	{
		while (tmp1)
		{
			if (tmp2->content < tmp1->content && tmp2->lis == tmp1->lis)
			{
				tmp1->lis++;
				if (i < tmp1->lis)
					i = tmp1->lis;
			}
			tmp1 = tmp1->next;
		}
		tmp2 = tmp2->next;
		tmp1 = tmp2->next;
	}
	ft_subsequence2(tmp2, i);
}

void	ft_empty_a(t_heads *heads, char **ret)
{
	while (heads->head_b != NULL)
	{
		ft_push(&heads->head_a, &heads->head_b);
		*ret = ft_strjoin2(*ret, "pa\n");
		if (heads->head_a->next != NULL)
		{
			ft_rotate(&heads->head_a);
			*ret = ft_strjoin2(*ret, "ra\n");
		}
	}
}

void	ft_rotation(t_heads *heads, char **ret)
{
	int	rotate;

	rotate = ft_position(heads->head_a);
	if (rotate <= (ft_lstsize(heads->head_a) + 1) / 2)
	{
		while (rotate > 0)
		{
			ft_rotate(&heads->head_a);
			*ret = ft_strjoin2(*ret, "ra\n");
			rotate--;
		}
	}
	else
	{
		rotate = ft_lstsize(heads->head_a) - rotate;
		while (rotate > 0)
		{
			ft_reverse_r(&heads->head_a);
			*ret = ft_strjoin2(*ret, "rra\n");
			rotate--;
		}
	}
}

char	*ft_pushflags(t_heads *heads, char *ret)
{
	int	i;
	int	len;

	i = 0;
	len = ft_lstsize(heads->head_a);
	while (i < len)
	{
		if (heads->head_a->flag == 0)
		{
			ft_push(&heads->head_b, &heads->head_a);
			ret = ft_strjoin2(ret, "pb\n");
		}
		else
		{
			ft_rotate(&heads->head_a);
			ret = ft_strjoin2(ret, "ra\n");
		}
		i++;
	}
	if (!heads->head_a)
		ft_empty_a(heads, &ret);
	while (heads->head_b)
		ret = ft_idealmove_values(heads, ret);
	ft_rotation(heads, &ret);
	return (ret);
}

int	ft_findmin(t_list *head)
{
	t_list	*tmp;
	int		min;

	min = 2147483647;
	tmp = head;
	while (1)
	{
		if (tmp->moving < min)
			min = tmp->moving;
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	return (min);
}
