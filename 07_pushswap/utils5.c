/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:14:16 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/30 16:14:18 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_after_spaces(char **argv)
{
	int	j;

	j = 0;
	while (argv[1][j] == ' ')
		j++;
	return (j);
}

int	ft_one_arg(char **argv, int j)
{
	while (argv[1][j])
	{
		if ((ft_isalpha(argv[1][j]))
		|| (!(ft_isdigit(argv[1][j])) && (argv[1][j] != ' ')
		&& (argv[1][j] != '-')) || ((ft_isdigit(argv[1][j]))
		&& ((argv[1][j + 1] != ' ') && (!(ft_isdigit(argv[1][j])))))
		|| ((argv[1][j] == '-') && ((argv[1][j - 1])
		&& (argv[1][j - 1] != ' '))) || ((argv[1][j] == '-')
		&& (argv[1][j + 1]) && (!ft_isdigit(argv[1][j + 1]))))
			return (1);
		j++;
	}
	return (0);
}

int	ft_many_args(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (((!ft_strcmp(argv[i], "-v")) && i != 1) || (argv[1][2]
				&& !(ft_strncmp(argv[1], "-v", 2))) || ((((argv[i][1])
				&& argv[i][0] == '-') && (!ft_isdigit(argv[i][1])))
				&& ((argv[i][1] != 'v'))) || (ft_isalpha(argv[i][j]) && i != 1)
				|| ft_isalpha(argv[i][0]) || (ft_isdigit(argv[i][j])
				&& argv[i][j + 1] && argv[i][j + 1] != ' '
				&& !ft_isdigit(argv[i][j + 1])) || (ft_isdigit(argv[i][j])
				&& argv[i][j - 1] && argv[i][j - 1] != ' '
				&& !ft_isdigit(argv[i][j - 1]) && argv[i][j - 1] != '-')
				|| (!(ft_isdigit(argv[i][0])) && (argv[i][0] != '-'))
				|| (argv[i][0] == '-' && !argv[i][1]))
				return (1);
			j++;
		}
	}
	return (0);
}

int	ft_check2(char **argv, int i, int j)
{
	if (ft_isalpha(argv[i][j]) || (ft_isdigit(argv[i][j])
		&& argv[i][j + 1] && argv[i][j + 1] != ' '
		&& !ft_isdigit(argv[i][j + 1])) || (ft_isdigit(argv[i][j])
		&& argv[i][j - 1] && argv[i][j - 1] != ' '
		&& !ft_isdigit(argv[i][j - 1]) && argv[i][j - 1] != '-')
		|| (!(ft_isdigit(argv[i][0])) && (argv[i][0] != '-'))
		|| (argv[i][0] == '-' && !argv[i][1]))
		return (1);
	return (0);
}
