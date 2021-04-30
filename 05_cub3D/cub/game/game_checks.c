/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:24:32 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/07 17:24:33 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

int	is_color_filled(t_color *color)
{
	if (color->red && color->green && color->blue)
	{
		if (ft_atoi(color->red) > 255)
			return (0);
		if (ft_atoi(color->green) > 255)
			return (0);
		if (ft_atoi(color->blue) > 255)
			return (0);
		color->n_color = (1 << 24 | ft_atoi(color->red) << 16
				| ft_atoi(color->green) << 8 | ft_atoi(color->blue));
		return (1);
	}
	return (0);
}

int	is_map_moment(t_game *game)
{
	if (game->res_h && game->res_w
		&& game->no_texture && game->so_texture
		&& game->we_texture && game->ea_texture
		&& game->sprite_texture
		&& is_color_filled(game->fcolor))
	{
		if (game->bonus)
		{
			if (game->skybox)
				return (1);
		}
		else
		{
			if (is_color_filled(game->ccolr))
				return (1);
		}
	}
	return (0);
}

int	is_texture_valid(char *text_name)
{
	if (check_suffix(text_name, ".xpm"))
	{
		if (open((const char *)text_name, 00) >= 0)
		{
			close(*text_name);
			return (1);
		}
	}
	printf("Error\ntexture %s not valid\n", text_name);
	return (0);
}

int	validator(t_game *game)
{
	if (is_texture_valid(game->no_texture))
	{
		if (is_texture_valid(game->so_texture))
		{
			if (is_texture_valid(game->we_texture))
			{
				if (is_texture_valid(game->ea_texture))
				{
					if (is_texture_valid(game->sprite_texture))
					{
						if (ft_strlen(game->skybox))
						{
							if (is_texture_valid(game->skybox))
								return (1);
							else
								return (0);
						}
						return (1);
					}
				}
			}
		}
	}
	return (0);
}

int	are_game_ok(t_game *game)
{
	if (is_map_moment(game)
		&& is_map_valid(game->map)
		&& validator(game))
	{
		mat_size(game);
		return (1);
	}
	return (0);
}
