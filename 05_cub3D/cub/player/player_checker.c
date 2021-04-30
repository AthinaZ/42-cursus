/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:28:14 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/07 17:28:17 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

int	just_one_player(char **map)
{
	int		y_index;
	int		x_index;
	char	pos;

	pos = 0;
	y_index = 0;
	while (map[y_index])
	{
		x_index = 0;
		while (map[y_index][x_index])
		{
			if (is_in_cset(map[y_index][x_index], "NEWS"))
			{
				if (!pos)
					pos = map[y_index][x_index];
				else
					return (0);
			}
			x_index++;
		}
		y_index++;
	}
	if (!pos)
		return (0);
	return (1);
}

static void	plane_positioner(t_player *player, char dir)
{
	plane_cleaner(player->plane);
	if (dir == 'N')
	{
		player->plane->dir_y = -1;
		player->plane->plane_x = -0.66;
	}
	if (dir == 'W')
	{
		player->plane->dir_x = -1;
		player->plane->plane_y = 0.66;
	}
	if (dir == 'S')
	{
		player->plane->dir_y = 1;
		player->plane->plane_x = 0.66;
	}
	if (dir == 'E')
	{
		player->plane->dir_x = 1;
		player->plane->plane_y = -0.66;
	}
}

static void	player_directioner(t_player *player, char dir)
{
	if (dir == 'E')
		player->tilt = 0;
	if (dir == 'N')
		player->tilt = M_PI / 2;
	if (dir == 'W')
		player->tilt = M_PI;
	if (dir == 'S')
		player->tilt = 3 * M_PI / 2;
}

void	player_positioner(t_player *player, int pos_x, int pos_y, char dir)
{
	player->pos_x = pos_x + 0.5;
	player->pos_y = pos_y + 0.5;
	player_directioner(player, dir);
	plane_positioner(player, dir);
}

void	where_is_the_player(char **map, t_player *player)
{
	int		x_index;
	int		y_index;
	char	c;

	x_index = 0;
	y_index = 0;
	while (map[y_index])
	{
		x_index = 0;
		c = map[y_index][x_index];
		while (c)
		{
			if (is_in_cset(c, "NEWS"))
			{
				player_positioner(player, x_index, y_index, c);
				map[y_index][x_index] = '0';
				return ;
			}
			x_index++;
			c = map[y_index][x_index];
		}
		y_index++;
	}
}
