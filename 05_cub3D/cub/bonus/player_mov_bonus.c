/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:20:32 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/07 17:20:35 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static void	straight_mov_b(t_player *player, char dir, char **map)
{
	t_plane	*plane;

	plane = player->plane;
	if (dir == 'B')
	{
		if (map[(int)(player->pos_y)]
			[(int)(player->pos_x + plane->dir_x * player->speed)] == '0')
			player->pos_x += plane->dir_x * player->speed;
		if (map[(int)(player->pos_y + plane->dir_y * player->speed)]
			[(int)(player->pos_x)] == '0')
			player->pos_y += plane->dir_y * player->speed;
	}
	else if (dir == 'F')
	{
		if (map[(int)(player->pos_y)]
			[(int)(player->pos_x - plane->dir_x * player->speed)] == '0')
			player->pos_x -= plane->dir_x * player->speed;
		if (map[(int)(player->pos_y - plane->dir_y * player->speed)]
			[(int)(player->pos_x)] == '0')
			player->pos_y -= plane->dir_y * player->speed;
	}
}

static void	side_mov_b(t_player *player, int dir, char **map)
{
	if (dir == 'R')
	{
		if (map[(int)player->pos_y][(int)(player->pos_x - player->plane->plane_x
						* 5 * player->speed)] == '0')
			player->pos_x -= (player->plane->plane_x * player->speed);
		if (map[(int)(player->pos_y - player->plane->plane_y
					* 5 * player->speed)][(int)player->pos_x] == '0')
			player->pos_y -= (player->plane->plane_y * player->speed);
	}
	else if (dir == 'L')
	{
		if (map[(int)player->pos_y][(int)(player->pos_x + player->plane->plane_x
						* 5 * player->speed)] == '0')
			player->pos_x += (player->plane->plane_x * player->speed);
		if (map[(int)(player->pos_y + player->plane->plane_y
					* 5 * player->speed)][(int)player->pos_x] == '0')
			player->pos_y += (player->plane->plane_y * player->speed);
	}
}

void	player_movement_b(t_keys *keys, t_player *player, char **map)
{
	if (keys->shift)
		player->speed = RUNNING_SPEED;
	else if (!keys->shift)
		player->speed = NORMAL_SPEED;
	if (keys->right_arrow)
		decrement_degree(&player->tilt, R_VEL, player->plane);
	if (keys->left_arrow)
		increment_degree(&player->tilt, R_VEL, player->plane);
	if (keys->w_key)
		straight_mov_b(player, 'B', map);
	if (keys->a_key)
		side_mov_b(player, 'L', map);
	if (keys->s_key)
		straight_mov_b(player, 'F', map);
	if (keys->d_key)
		side_mov_b(player, 'R', map);
}
