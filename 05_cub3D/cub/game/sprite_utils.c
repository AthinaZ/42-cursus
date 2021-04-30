/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:25:14 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/07 17:25:15 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

int	sprite_counter(char **map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '2')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	sprites_filler(t_game *game)
{
	int	x;
	int	y;
	int	sprite_index;

	y = 0;
	sprite_index = 0;
	game->s_cords = ft_calloc(sizeof(t_coords),
			((sprite_counter(game->map) + 1)));
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '2')
			{
				game->s_cords[sprite_index].x = x + 0.5;
				game->s_cords[sprite_index].y = y + 0.5;
				sprite_index++;
			}
			x++;
		}
		y++;
	}
	game->s_count = sprite_counter(game->map);
}

float	sprite_dist(t_coords *s_cords, t_player *player)
{
	float	dist_x;
	float	dist_y;

	dist_x = (player->pos_x - s_cords->x) * (player->pos_x - s_cords->x);
	dist_y = (player->pos_y - s_cords->y) * (player->pos_y - s_cords->y);
	return (dist_x + dist_y);
}

void	sprite_sorter(t_coords *s_cords, t_player *player, t_game *game)
{
	int			index_x;
	int			index_y;
	t_coords	temp_c;

	index_y = 0;
	while (index_y < game->s_count)
	{
		index_x = 0;
		while (index_x < game->s_count)
		{
			if (sprite_dist(&s_cords[index_y], player)
				> sprite_dist(&s_cords[index_x], player))
			{
				temp_c = s_cords[index_y];
				s_cords[index_y] = s_cords[index_x];
				s_cords[index_x] = temp_c;
			}
			index_x++;
		}
		index_y++;
	}
}
