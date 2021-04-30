/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:51:25 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/07 17:51:27 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

int	just_right_chars(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!is_in_cset(map[y][x], "012 NEWS"))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_map(char **map)
{
	int	y_index;

	y_index = 0;
	if (mat_len(map) < 3)
		return (0);
	if (intermidiate_row("", map[y_index], map[y_index + 1]))
	{
		y_index++;
		while (y_index < (int)mat_len(map) - 1)
		{
			if (!intermidiate_row(map[y_index - 1], map[y_index],
					map[y_index + 1]))
				return (0);
			y_index++;
		}
		if (intermidiate_row("", map[y_index], map[y_index + -1]))
			return (1);
	}
	return (0);
}

int	is_map_valid(char **map)
{
	if (just_one_player(map) && just_right_chars(map) && check_map(map))
	{
		return (1);
	}
	return (0);
}
