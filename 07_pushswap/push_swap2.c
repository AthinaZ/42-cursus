/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:12:33 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/30 16:12:35 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issorted(t_list *lst)
{
	int		mem;
	t_list	*tmp;

	if (lst == NULL)
		return (1);
	tmp = lst;
	mem = tmp->content;
	while (tmp->next)
	{
		if (tmp->next->content < mem)
			return (0);
		tmp = tmp->next;
		mem = tmp->content;
	}
	return (1);
}

void	ft_argparsing(int argc, char **argv, t_list **head, int j)
{
	int		i;
	t_list	*tmp;
	char	**arr;

	i = 1;
	j = 0;
	while (i < argc)
	{
		arr = ft_split(argv[i], ' ');
		while (arr[j])
		{
			if (i == 1 && j == 0)
				*head = ft_lstnew(ft_atoi(arr[j]));
			else
			{
				tmp = ft_lstnew(ft_atoi(arr[j]));
				ft_lstadd_back(*head, tmp);
			}
			free(arr[j]);
			j++;
		}
		free(arr);
		i++;
		j = 0;
	}
}

void	ft_checkduplicates(t_list *head)
{
	int		mem;
	t_list	*tmp1;
	t_list	*tmp2;

	if (head == NULL)
		return ;
	tmp1 = head;
	tmp2 = tmp1;
	mem = tmp1->content;
	while (tmp2->next)
	{
		while (tmp1->next)
		{
			if (tmp1->next->content == mem)
				ft_error();
			tmp1 = tmp1->next;
		}
		tmp2 = tmp2->next;
		tmp1 = tmp2;
		mem = tmp1->content;
	}
}

void	ft_checkargs(int argc, char **argv)
{
	int	i;
	int	j;
	int	one_arg;

	i = 1;
	j = 0;
	one_arg = 0;
	if (argc == 2)
		one_arg = ft_one_arg(argv, j);
	else
	{
		while (i < argc)
		{
			while (argv[i][j])
			{
				if (ft_check2(argv, i, j))
					ft_error();
				j++;
			}
			j = 0;
			i++;
		}
	}
}

void	ft_subsequence2(t_list *tmp2, int i)
{
	while (tmp2)
	{
		if (tmp2->lis == i)
		{
			tmp2->flag++;
			i--;
		}
		tmp2 = tmp2->prev;
	}
}
