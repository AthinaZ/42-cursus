/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:30:54 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/07 17:30:55 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

void	ray_pos_and_dir(t_caster *caster, t_game *game,
							t_player *player, int x)
{
	caster->camera_x = 2 * x / (double)game->res_w_nu - 1;
	caster->ray_dir_x = player->plane->dir_x - player->plane->plane_x
		* caster->camera_x;
	caster->ray_dir_y = player->plane->dir_y - player->plane->plane_y
		* caster->camera_x;
	caster->map_x = (int)(player->pos_x);
	caster->map_y = (int)(player->pos_y);
	caster->delta_dist_x = fabs(1 / caster->ray_dir_x);
	caster->delta_dist_y = fabs(1 / caster->ray_dir_y);
}

void	ray_collider(t_caster *caster, t_player *player)
{
	caster->hit = 0;
	if (caster->ray_dir_x < 0)
	{
		caster->step_x = -1;
		caster->side_dist_x = (player->pos_x - caster->map_x)
			* caster->delta_dist_x;
	}
	else
	{
		caster->step_x = 1;
		caster->side_dist_x = (caster->map_x + 1.0 - player->pos_x)
			* caster->delta_dist_x;
	}
	if (caster->ray_dir_y < 0)
	{
		caster->step_y = -1;
		caster->side_dist_y = (player->pos_y - caster->map_y)
			* caster->delta_dist_y;
	}
	else
	{
		caster->step_y = 1;
		caster->side_dist_y = (caster->map_y + 1.0 - player->pos_y)
			* caster->delta_dist_y;
	}
}

void	ray_dda(t_caster *caster, t_game *game)
{
	while (caster->hit == 0)
	{
		if (caster->side_dist_x < caster->side_dist_y)
		{
			caster->side_dist_x += caster->delta_dist_x;
			caster->map_x += caster->step_x;
			caster->side = 0;
		}
		else
		{
			caster->side_dist_y += caster->delta_dist_y;
			caster->map_y += caster->step_y;
			caster->side = 1;
		}
		if (game->map[caster->map_y][caster->map_x] == '1')
			caster->hit = 1;
	}
}

void	line_measure_dist(t_caster *caster, t_game *game,
							t_player *player)
{
	if (caster->side == 0)
		caster->perp_wall_dist = (caster->map_x - player->pos_x
				+ (1 - caster->step_x) / 2) / caster->ray_dir_x;
	else
		caster->perp_wall_dist = (caster->map_y - player->pos_y
				+ (1 - caster->step_y) / 2) / caster->ray_dir_y;
	caster->line_height = (int)(game->res_h_nu / caster->perp_wall_dist);
	caster->draw_start = -caster->line_height / 2 + game->res_h_nu / 2;
	if (caster->draw_start < 0)
		caster->draw_start = 0;
	caster->draw_end = caster->line_height / 2 + game->res_h_nu / 2;
	if (caster->draw_end >= game->res_h_nu || caster->draw_end < 0)
		caster->draw_end = game->res_h_nu - 1;
}

void	ver_line(int x, t_caster *caster, t_window *win, t_data *img)
{
	int			i;
	t_texture	*tex;

	i = 0;
	while (++i < caster->draw_start)
	{
		if (!win->game->skybox || win->game->bonus == 0)
			my_mlx_pixel_put(img, x, i, win->game->ccolr->n_color);
		else
		{
			tex = win->textuures->skybox;
			my_mlx_pixel_put(img, x, i,
			tex->addr[(int)(win->plr->tilt * tex->img_w) + i * tex->img_w + x]);
		}
	}
	while (++i < caster->draw_end)
	{
		caster->tex_y = (int)caster->tex_pos & (tex->img_h - 1);
		caster->tex_pos += caster->step;
		tex = texture_selector(win, caster);
		my_mlx_pixel_put(img, x, i, tex->addr[tex->img_h
							* caster->tex_y + caster->tex_x]);
	}
	while (++i < win->game->res_h_nu)
		my_mlx_pixel_put(img, x, i, win->game->fcolor->n_color);
}
