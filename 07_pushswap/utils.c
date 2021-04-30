/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:13:21 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/30 16:13:22 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	long int		i;
	int				x;
	int				sign;
	int				count;

	i = 0;
	x = 0;
	count = 0;
	sign = 1;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == 32)
		x++;
	if (str[x] == '+' || str[x] == '-')
	{
		if (str[x] == '-')
			sign = -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9' && count++ > -1)
		i = i * 10 + ((int)str[x++] - '0');
	if (i > 2147483647 ||i < -2147483648)
		ft_error();
	return ((int)i * sign);
}

t_list	*ft_lstnew(int content)
{
	t_list	*ret;

	ret = malloc(sizeof(t_list));
	if (ret == NULL)
		return (NULL);
	ret->content = content;
	ret->next = NULL;
	ret->prev = NULL;
	ret->flag = 0;
	ret->lis = 1;
	ret->pa = 0;
	ret->pb = 0;
	ret->moving = 0;
	return (ret);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp != NULL && temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list	*temp;

	if (lst == NULL)
		lst = new;
	else
	{
		temp = ft_lstlast(lst);
		temp->next = new;
		new->prev = temp;
	}
}

int	ft_numlen(int num)
{
	int	i;

	i = 1;
	if (num < 0)
		i += 1;
	if (num == 0)
		return (2);
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}
