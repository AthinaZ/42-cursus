/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:25:01 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/07 17:25:03 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

char	*take_value_s_cub_parser(char **str, int offset)
{
	*str += offset;
	ft_jump_spaces(str);
	if (ft_strlen(*str))
		return (ft_strdup(*str));
	else
		return (0);
}

void	fill_color(char **str, int offset, t_color *color)
{
	*str += offset;
	ft_jump_spaces(str);
	if (ft_isdigit(**str))
		color->red = ft_substr(*str, 0, ft_numlen(str));
	if (**str == ',')
	{
		*str += 1;
		if (ft_isdigit(**str))
			color->blue = ft_substr(*str, 0, ft_numlen(str));
	}
	if (**str == ',')
	{
		*str += 1;
		if (ft_isdigit(**str))
			color->green = ft_substr(*str, 0, ft_numlen(str));
	}
}

void	free_game(t_game *game)
{
	free_if_exists((void **)&game->res_w);
	free_if_exists((void **)&game->res_h);
	free_if_exists((void **)&game->no_texture);
	free_if_exists((void **)&game->so_texture);
	free_if_exists((void **)&game->ea_texture);
	free_if_exists((void **)&game->we_texture);
	free_if_exists((void **)&game->sprite_texture);
	free_if_exists((void **)&game->skybox);
	free_if_exists((void **)&game->ccolr->red);
	free_if_exists((void **)&game->ccolr->green);
	free_if_exists((void **)&game->ccolr->blue);
	free_if_exists((void **)&game->fcolor->red);
	free_if_exists((void **)&game->fcolor->green);
	free_if_exists((void **)&game->fcolor->blue);
	free_if_exists((void **)&game->s_cords);
	free_mat((void **)(game->map));
	free_if_exists((void **)&game->map);
}

void	resize_to_screen_size(t_game *game, t_window *window)
{
	int	max_x;
	int	max_y;

	mlx_get_screen_size(window->mlx, &max_x, &max_y);
	if (game->res_w_nu > max_x)
		game->res_w_nu = max_x;
	if (game->res_h_nu > max_y)
		game->res_h_nu = max_y;
}
