/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:13:47 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/30 16:13:48 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_argparsing2(char **arr, t_list **head, int j, t_list *tmp)
{
	tmp = ft_lstnew(ft_atoi(arr[j]));
	ft_lstadd_back(*head, tmp);
}

int	ft_argparsing3(char **arr, int j)
{
	free(arr[j]);
	j++;
	return (j);
}

void	ft_printzero(t_list *tmp)
{
	if (tmp-> content == 0)
		write(1, "0", 1);
	else
		write(1, ft_itoa(tmp->content), ft_numlen(tmp->content));
}

int	ft_strcmp(char *s1, char *s2)
{
	int	x;

	x = 0;
	while (s1[x] != '\0' && s1[x] == s2[x])
		x++;
	return (s1[x] - s2[x]);
}
