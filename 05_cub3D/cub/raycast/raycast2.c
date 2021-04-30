/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:31:09 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/07 17:31:11 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

t_texture	*texture_selector(t_window *window, t_caster *caster)
{
	if (caster->side == 0)
	{
		if (caster->ray_dir_x > 0)
			return (window->textuures->e_texture);
		else
			return (window->textuures->w_texture);
	}
	else
	{
		if (caster->ray_dir_y > 0)
			return (window->textuures->s_textture);
		else
			return (window->textuures->n_texture);
	}
}

void	texturer(t_caster *caster, t_player *player,
					t_game *game, t_window *window)
{
	t_texture	*texture;

	texture = texture_selector(window, caster);
	if (caster->side == 0)
		caster->wall_x = player->pos_y + caster->perp_wall_dist
			* caster->ray_dir_y;
	else
		caster->wall_x = player->pos_x + caster->perp_wall_dist
			* caster->ray_dir_x;
	caster->wall_x -= floor((caster->wall_x));
	caster->tex_x = (int)(caster->wall_x * (double)(texture->img_w));
	if (caster->side == 0 && caster->ray_dir_x > 0)
		caster->tex_x = texture->img_w - caster->tex_x - 1;
	if (caster->side == 1 && caster->ray_dir_y < 0)
		caster->tex_x = texture->img_w - caster->tex_x - 1;
	caster->step = 1.0 * texture->img_h / caster->line_height;
	caster->tex_pos = (caster->draw_start - game->res_h_nu / 2
			+ caster->line_height / 2) * caster->step;
}
