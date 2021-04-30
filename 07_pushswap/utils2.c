/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:13:30 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/30 16:13:32 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int	ft_isc(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const char	*p1;
	const char	*p2;

	p1 = s1;
	p2 = s2;
	while (*p1 && *p1 == *p2 && n)
	{
		p1++;
		p2++;
		n--;
	}
	if (n > 0)
		return ((unsigned char)*p1 - (unsigned char)*p2);
	else
		return (0);
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = lst;
	if (temp == NULL)
		return (0);
	if (temp->next == NULL)
		return (1);
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
