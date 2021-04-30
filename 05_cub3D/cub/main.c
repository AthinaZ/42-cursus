/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:49:22 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/07 17:49:24 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

int	update(t_window *window)
{
	t_data		image;

	player_movement(window->keys, window->plr, window->game->map);
	new_image(&image, window,
				window->game->res_w_nu, window->game->res_h_nu);
	cast_ray(window->plr, window->game, &image, window);
	mlx_put_image_to_window(window->mlx, window->mlx_win, image.img, 0, 0);
	mlx_destroy_image(window->mlx, image.img);
	if (window->keys->esc)
		close_game(window);
	if (window->game->save)
		screenshot(window, &image);
	return (1);
}

void	engine_starter(t_window *window)
{
	mlx_hook(window->mlx_win, 06, 0L, mouse_pos_mov, window);
	mlx_hook(window->mlx_win, 02, 0L, key_hook_in, window);
	mlx_hook(window->mlx_win, 03, 0L, key_hook_out, window);
	mlx_hook(window->mlx_win, 17, 0L, close_game, window);
	mlx_loop_hook(window->mlx, update, window);
	mlx_loop(window->mlx);
}

int	ret_error(void)
{
	printf("Error\nwrong number of arguments, or wrong arguments");
	return (-1);
}

int	fillers(t_game *game, char *filename, t_window *window)
{
	if (!game_filler(game, filename))
		return (-1);
	window->game = game;
	clean_window_struct(window);
	start_win(window, game);
	if (!validator(game))
		return (-1);
	textures_filler(window);
	engine_starter(window);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game		game[1];
	t_window	window;

	if (argc > 1)
	{
		game_cleaner(game);
		if (argc > 2 && check_string(argv[2], "--save"))
			game->save = 1;
		if (check_suffix(argv[1], ".cub"))
		{
			if (fillers(game, argv[1], &window) < 0)
				return (-1);
		}
		else
			return (ret_error());
	}
	return (ret_error());
}
