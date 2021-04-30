/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritecast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:31:29 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/07 17:31:30 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

void	sprite_positioner(t_player *player, t_game *game, int i)
{
	t_s_caster	*s_caster;

	s_caster = player->caster->sprite_caster;
	s_caster->sprite_x = game->s_cords[i].x - player->pos_x;
	s_caster->sprite_y = game->s_cords[i].y - player->pos_y;
}

void	sprite_dimensioner(t_player *player, t_game *game)
{
	t_s_caster	*s_caster;

	s_caster = player->caster->sprite_caster;
	s_caster->inv_det = 1.0 / (player->plane->plane_x * player->plane->dir_y
			- player->plane->dir_x * player->plane->plane_y);
	s_caster->transform_x = s_caster->inv_det * (player->plane->dir_y
			* s_caster->sprite_x - player->plane->dir_x * s_caster->sprite_y);
	s_caster->transform_y = s_caster->inv_det * ((-player->plane->plane_y)
			* s_caster->sprite_x + player->plane->plane_x * s_caster->sprite_y);
	s_caster->sprite_screen_x = game->res_w_nu - (int)((game->res_w_nu / 2)
			* (1 + s_caster->transform_x / s_caster->transform_y));
	s_caster->v_move_screen = (int)(0.0 / s_caster->transform_y);
	s_caster->sprite_height = (abs((int)(game->res_h_nu
					/ s_caster->transform_y))) / 1;
}

void	sprite_painting_coords_y(t_player *player, t_game *game)
{
	t_s_caster	*s_caster;

	s_caster = player->caster->sprite_caster;
	s_caster->draw_start_y = -s_caster->sprite_height / 2
		+ game->res_h_nu / 2 + s_caster->v_move_screen;
	if (s_caster->draw_start_y < 0)
		s_caster->draw_start_y = 0;
	s_caster->draw_end_y = s_caster->sprite_height / 2 + game->res_h_nu
		/ 2 + s_caster->v_move_screen;
	if (s_caster->draw_end_y >= game->res_h_nu)
		s_caster->draw_end_y = game->res_h_nu - 1;
}

void	sprite_painting_coords_x(t_player *player, t_game *game)
{
	t_s_caster	*s_caster;

	s_caster = player->caster->sprite_caster;
	s_caster->sprite_width = (abs((int)(game->res_h_nu
					/ s_caster->transform_y))) / 1;
	s_caster->draw_start_x = -s_caster->sprite_width
		/ 2 + s_caster->sprite_screen_x;
	if (s_caster->draw_start_x < 0)
		s_caster->draw_start_x = 0;
	s_caster->draw_end_x = s_caster->sprite_width
		/ 2 + s_caster->sprite_screen_x;
	if (s_caster->draw_end_y >= game->res_w_nu)
		s_caster->draw_end_x = game->res_w_nu - 1;
}
