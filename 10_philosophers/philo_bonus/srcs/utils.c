/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:49:22 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/09 15:49:24 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	parse(t_args *t, int ac, char **av)
{
	t->nb_philos = ft_atoi(av[1]);
	t->t_die = ft_atoi(av[2]);
	t->t_eat = ft_atoi(av[3]);
	t->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		t->nb_must_eat = ft_atoi(av[5]);
	else
		t->nb_must_eat = -1;
	return ;
}

int	isallnum(char **av, int i, int j)
{
	while (av[j])
	{
		while (av[j][i])
		{
			if (av[j][i] < '0' || av[j][i] > '9')
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

static int	ft_spaces(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	nbr;
	long	sign;
	size_t	i;

	nbr = 0;
	sign = 1;
	i = 0;
	while ((str[i] != '\0') && ft_spaces(str[i]) == 1)
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] != '\0') && ('0' <= str[i]) && (str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if (nbr > 2147483647 && sign == 1)
			return (-1);
		if (nbr > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (sign * nbr);
}
