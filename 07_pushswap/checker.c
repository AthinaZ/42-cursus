/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:10:55 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/30 16:10:58 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checkargs(int argc, char **argv)
{
	int	one_arg;
	int	many_args;
	int	j;

	one_arg = 0;
	many_args = 0;
	j = 0;
	if (argc == 2)
		one_arg = ft_one_arg(argv, j);
	else if (argc > 2)
		many_args = ft_many_args(argv);
	if ((one_arg == 1 || many_args == 1))
		ft_error();
}

void	ft_argparsing(int argc, char **argv, t_list **head, int j)
{
	int		i;
	t_list	*tmp;
	char	**arr;

	tmp = NULL;
	i = 1;
	j = 0;
	if (ft_strncmp(argv[1], "-v", 2) == 0)
		i = 2;
	while (i < argc)
	{
		arr = ft_split(argv[i], ' ');
		while (arr[j])
		{
			if ((i == 1 || (i == 2 && ft_strncmp(argv[1], "-v", 2) == 0))
				&& j == 0)
				*head = ft_lstnew(ft_atoi(arr[j]));
			else
				ft_argparsing2(arr, head, j, tmp);
			j = ft_argparsing3(arr, j);
		}
		free(arr);
		i++;
		j = 0;
	}
}

int	ft_sortedlist(t_heads heads)
{
	int		mem;
	t_list	*tmp;

	if (heads.head_b == NULL)
	{
		if (heads.head_a == NULL)
			return (1);
		tmp = heads.head_a;
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
	else
		return (0);
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

int	main(int argc, char **argv)
{
	char	*line;
	t_heads	heads;
	int		flag;

	flag = 0;
	heads.head_a = NULL;
	heads.head_b = NULL;
	if (argc == 1)
		exit (0);
	if (!(ft_strncmp(argv[1], "-v", 2)))
		flag = 1;
	ft_checkargs(argc, argv);
	ft_argparsing(argc, argv, &heads.head_a, 0);
	ft_checkduplicates(heads.head_a);
	ft_printalo(&heads, flag);
	while (ft_get_next_line(0, &line))
	{
		ft_parseline(line, &heads);
		ft_printalo(&heads, flag);
	}
	if (ft_sortedlist(heads))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit (0);
}
