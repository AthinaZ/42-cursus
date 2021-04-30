/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:30:36 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/07 17:30:39 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

void	cast_ray(t_player *player, t_game *game,
						t_data *img, t_window *window)
{
	t_caster	*caster;
	int			x;

	x = 0;
	caster = player->caster;
	zero_caster(caster);
	caster->z_buffer = ft_calloc(sizeof(float), game->res_w_nu + 1);
	while (x < game->res_w_nu)
	{
		zero_caster(caster);
		ray_pos_and_dir(caster, game, player, x);
		ray_collider(caster, player);
		ray_dda(caster, game);
		line_measure_dist(caster, game, player);
		texturer(caster, player, game, window);
		ver_line(x, caster, window, img);
		caster->z_buffer[x] = caster->perp_wall_dist;
		x++;
	}
	sprite_caster(player, game, img, window);
	free(caster->z_buffer);
}

void	sprite_caster(t_player *player, t_game *game,
							t_data *img, t_window *window)
{
	int			s_index;
	t_caster	*caster;

	caster = player->caster;
	s_index = 0;
	sprite_sorter(game->s_cords, player, game);
	while (s_index < game->s_count)
	{
		zero_s_caster(caster->sprite_caster);
		sprite_positioner(player, game, s_index);
		sprite_dimensioner(player, game);
		sprite_painting_coords_y(player, game);
		sprite_painting_coords_x(player, game);
		sprite_print(player, game, img, window);
		s_index++;
	}
}
