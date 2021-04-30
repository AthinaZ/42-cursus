/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:12:15 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/30 16:12:17 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_two(t_heads *heads, char **ret)
{
	if (heads->head_a->content > heads->head_a->next->content)
		ft_swap(&heads->head_a);
	*ret = ft_strjoin2(*ret, "sa\n");
}

void	ft_three(t_heads *heads, char **ret)
{
	if (heads->head_a->content < heads->head_a->next->content)
	{
		ft_reverse_r(&heads->head_a);
		*ret = ft_strjoin2(*ret, "rra\n");
		if (!ft_issorted(heads->head_a))
		{
			ft_swap(&heads->head_a);
			*ret = ft_strjoin2(*ret, "sa\n");
		}
	}
	else if (ft_largest(heads) == 1)
	{
		ft_rotate(&heads->head_a);
		*ret = ft_strjoin2(*ret, "ra\n");
		if (!ft_issorted(heads->head_a))
		{
			ft_swap(&heads->head_a);
			*ret = ft_strjoin2(*ret, "sa\n");
		}
	}
	else
	{
		ft_swap(&heads->head_a);
		*ret = ft_strjoin2(*ret, "sa\n");
	}
}

void	ft_five2(t_heads *heads, char **ret)
{
	while (heads->head_b->pa)
	{
		if (ft_findpos(heads, heads->head_b) <= (ft_lstsize(heads->head_a) / 2))
		{
			ft_rotate(&heads->head_a);
			*ret = ft_strjoin2(*ret, "ra\n");
			heads->head_b->pa--;
		}
		else
		{
			ft_reverse_r(&heads->head_a);
			*ret = ft_strjoin2(*ret, "rra\n");
			heads->head_b->pa--;
		}
	}
	ft_push(&heads->head_a, &heads->head_b);
	*ret = ft_strjoin2(*ret, "pa\n");
}

void	ft_five(t_heads *heads, char **ret)
{
	ft_push(&heads->head_b, &heads->head_a);
	ft_push(&heads->head_b, &heads->head_a);
	*ret = ft_strjoin2(*ret, "pb\npb\n");
	if (!ft_issorted(heads->head_a))
		ft_three(heads, ret);
	heads->head_b->moving = ft_push_convenience(heads, heads->head_b);
	heads->head_b = heads->head_b->next;
	heads->head_b->moving = ft_push_convenience(heads, heads->head_b);
	heads->head_b = heads->head_b->prev;
	ft_five2(heads, ret);
	heads->head_b->moving = ft_push_convenience(heads, heads->head_b);
	ft_five2(heads, ret);
	ft_rotation(heads, ret);
}

int	main(int argc, char **argv)
{
	t_heads	heads;
	char	*ret;

	heads.head_a = NULL;
	heads.head_b = NULL;
	ret = ft_strnew(1);
	ft_checkargs(argc, argv);
	ft_argparsing(argc, argv, &heads.head_a, 0);
	ft_checkduplicates(heads.head_a);
	if (!ft_issorted(heads.head_a))
	{
		if (ft_lstsize(heads.head_a) == 2)
			ft_two(&heads, &ret);
		else if (ft_lstsize(heads.head_a) == 3)
			ft_three(&heads, &ret);
		else if (ft_lstsize(heads.head_a) == 5)
			ft_five(&heads, &ret);
		else
		{
			ft_subsequence(heads.head_a);
			ret = ft_pushflags(&heads, ret);
		}
	}
	write(1, ret, ft_strlen2(ret));
	exit (0);
}
