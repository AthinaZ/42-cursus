/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_fxns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:37:57 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/07 17:38:00 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

void	start_win(t_window *window, t_game *game)
{
	window->game = game;
	where_is_the_player(window->game->map, window->plr);
	clean_keys(window->keys);
	window->mlx = mlx_init();
	resize_to_screen_size(window->game, window);
	window->mlx_win = mlx_new_window(window->mlx, game->res_w_nu,
			game->res_h_nu, "CUB3D");
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	new_image(t_data *image, t_window *window, int width, int height)
{
	image->img = mlx_new_image(window->mlx, width, height);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
}

static void	free_win(t_window *window)
{
	free(window->textuures->e_texture->addr);
	free(window->textuures->n_texture->addr);
	free(window->textuures->s_textture->addr);
	free(window->textuures->w_texture->addr);
	free(window->textuures->sprite_texture->addr);
	if (window->game->bonus)
		free(window->textuures->skybox->addr);
}

int	close_game(t_window *window)
{
	mlx_destroy_window(window->mlx, window->mlx_win);
	free_game(window->game);
	free_win(window);
	exit(0);
	return (0);
}
