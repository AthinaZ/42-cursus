/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:19:55 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/07 17:19:58 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

int	calc_ratio(t_game *game, int relative_size)
{
	int	mat_len_x;
	int	mat_len_y;
	int	ratio;

	mat_len_x = game->map_size->size_x;
	mat_len_y = game->map_size->size_y;
	if (mat_len_x > mat_len_y)
		ratio = (game->res_w_nu / relative_size) / mat_len_x;
	else
		ratio = (game->res_h_nu / relative_size) / mat_len_y;
	return (ratio);
}

void	print_rect(t_data *img, float *origins, t_window *window,
						float size)
{
	int	x;
	int	y;

	x = origins[1] - size / 2;
	y = origins[0] - size / 2;
	while (y < origins[0] + size / 2)
	{
		x = origins[1] - size / 2;
		while (x < origins[1] + size / 2)
		{
			if (x > 0 && x < window->game->res_w_nu
				&& y > 0 && y < window->game->res_h_nu)
				my_mlx_pixel_put(img, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}
}

static void	minimap_printer(t_window *window, int mat_index, int ratio,
							t_data *img)
{
	int	index;
	int	x;
	int	y;

	index = -1;
	while (++index < (int)ft_strlen(window->game->map[mat_index]))
	{
		x = index * ratio - 1;
		while (++x < ratio * (index + 1))
		{
			y = ratio * mat_index - 1;
			while (++y < ratio * (mat_index + 1))
			{
				if (window->game->map[mat_index][index] == '1')
					my_mlx_pixel_put(img, x, y, 0x00000000);
				else if (window->game->map[mat_index][index] == '2')
					my_mlx_pixel_put(img, x, y, 0x0000FF00);
				else if (window->game->map[mat_index][index] == '0')
					my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
			}
		}
	}
}

void	minimap_img(t_data *img, t_window *window, t_player *player,
					int min_fract)
{
	size_t	mat_index;
	float	origins[2];
	int		ratio;

	mat_index = -1;
	ratio = calc_ratio(window->game, min_fract);
	while (window->game->map[++mat_index])
	{
		minimap_printer(window, mat_index, ratio, img);
	}
	origins[1] = player->pos_x * ratio;
	origins[0] = player->pos_y * ratio;
	print_rect(img, origins, window, ratio);
}
