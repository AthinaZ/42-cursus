/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:13:08 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/30 16:13:10 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_idealmoves2(t_heads *heads, char **ret, t_list *tmp, int pb)
{
	if (ft_node_pos(heads->head_b, tmp) <= (ft_lstsize(heads->head_b) / 2))
	{
		ft_rotate(&heads->head_b);
		*ret = ft_strjoin2(*ret, "rb\n");
		pb--;
		if (pb == 0)
			tmp = heads->head_b;
	}
	else
	{
		ft_reverse_r(&heads->head_b);
		*ret = ft_strjoin2(*ret, "rrb\n");
		pb--;
		if (pb == 0)
			tmp = heads->head_b;
	}
	return (pb);
}

int	ft_idealmoves3(t_heads *heads, char **ret, t_list *tmp, int pa)
{
	if (ft_findpos(heads, tmp) <= (ft_lstsize(heads->head_a) / 2))
	{
		ft_rotate(&heads->head_a);
		*ret = ft_strjoin2(*ret, "ra\n");
		pa--;
	}
	else
	{
		ft_reverse_r(&heads->head_a);
		*ret = ft_strjoin2(*ret, "rra\n");
		pa--;
	}
	return (pa);
}

void	ft_idealmoves5(t_heads *heads, char **ret, int i)
{
	if (i == 1)
	{
		ft_reverse_r(&heads->head_a);
		ft_reverse_r(&heads->head_b);
		*ret = ft_strjoin2(*ret, "rrr\n");
	}
	else
	{
		ft_rotate(&heads->head_a);
		ft_rotate(&heads->head_b);
		*ret = ft_strjoin2(*ret, "rr\n");
	}
}

void	ft_idealmoves4(t_heads *heads, char **ret, t_list *tmp, int	*p)
{
	while (p[0] || p[1])
	{
		if (ft_findpos(heads, tmp) > (ft_lstsize(heads->head_a) / 2) && ft_node_pos(heads->head_b, tmp) > (ft_lstsize(heads->head_b) / 2) \
		&& p[0] && p[1])
		{
			ft_idealmoves5(heads, ret, 1);
			p[0]--;
			p[1]--;
			if (p[1] == 0)
				tmp = heads->head_b;
		}
		else if (ft_findpos(heads, tmp) <= (ft_lstsize(heads->head_a) / 2) && ft_node_pos(heads->head_b, tmp) <= (ft_lstsize(heads->head_b) / 2) \
		&& p[0] && p[1])
		{
			ft_idealmoves5(heads, ret, 0);
			p[0]--;
			p[1]--;
			if (p[1] == 0)
				tmp = heads->head_b;
		}
		else if (p[0])
			p[0] = ft_idealmoves3(heads, ret, tmp, p[0]);
		else if (p[1])
			p[1] = ft_idealmoves2(heads, ret, tmp, p[1]);
	}
}

char 	*ft_idealmove_values(t_heads *heads, char *ret)
{
	t_list	*tmp;
	int		min;
	int		p[2];

	tmp = heads->head_b;
	while (tmp)
	{
		tmp->moving = ft_push_convenience(heads, tmp);
		tmp = tmp->next;
	}
	tmp = heads->head_b;
	min = ft_findmin(heads->head_b);
	while (tmp->moving != min)
		tmp = tmp->next;
	p[0] = tmp->pa;
	p[1] = tmp->pb;
	ft_idealmoves4(heads, &ret, tmp, p);
	ft_push(&heads->head_a, &heads->head_b);
	ret = ft_strjoin2(ret, "pa\n");
	return (ret);
}
