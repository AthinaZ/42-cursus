/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:24:43 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/07 17:24:44 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

static void	line_texture_analizer(char *str, t_game *game)
{
	ft_jump_spaces(&str);
	if (!str)
		return ;
	if (*str == 'N' && str[1] == 'O')
		game->no_texture = take_value_s_cub_parser(&str, 2);
	else if (*str == 'S' && str[1] == 'O')
		game->so_texture = take_value_s_cub_parser(&str, 2);
	else if (*str == 'W' && str[1] == 'E')
		game->we_texture = take_value_s_cub_parser(&str, 2);
	else if (*str == 'E' && str[1] == 'A')
		game->ea_texture = take_value_s_cub_parser(&str, 2);
	else if (*str == 'S')
		game->sprite_texture = take_value_s_cub_parser(&str, 1);
	else if (*str == 'B')
		game->skybox = take_value_s_cub_parser(&str, 1);
}

static void	line_measures_analizer(char *str, t_game *game)
{
	ft_jump_spaces(&str);
	if (!str)
		return ;
	if (*str == 'R')
	{
		str++;
		ft_jump_spaces(&str);
		if (ft_isdigit(*str))
		{
			game->res_w = ft_substr(str, 0, ft_numlen(&str));
			game->res_w_nu = ft_atoi(game->res_w);
		}
		else
			return ;
		ft_jump_spaces(&str);
		if (ft_isdigit(*str))
		{
			game->res_h = ft_substr(str, 0, ft_numlen(&str));
			game->res_h_nu = ft_atoi(game->res_h);
		}
		else
			return ;
	}
}

static void	line_colors_analizer(char *str, t_game *game)
{
	if (!str)
		return ;
	ft_jump_spaces(&str);
	if (*str == 'C')
		fill_color(&str, 1, game->ccolr);
	else if (*str == 'F')
		fill_color(&str, 1, game->fcolor);
}

static void	analizers(t_game *game, int game_fd)
{
	int		mat_start;
	char	*line;

	mat_start = 0;
	line = 0;
	while (ft_get_next_line(game_fd, &line))
	{
		line_texture_analizer(line, game);
		line_measures_analizer(line, game);
		line_colors_analizer(line, game);
		free(line);
		if (is_map_moment(game))
			break ;
	}
	while (ft_get_next_line(game_fd, &line))
	{
		if (ft_strlen(line))
			mat_start = 1;
		if (mat_start)
			add_string_to_mat(&game->map, line);
		free(line);
	}
	add_string_to_mat(&game->map, line);
	free(line);
}

int	game_filler(t_game *game, char *file_path)
{
	int		game_fd;

	game_fd = open(file_path, 00);
	analizers(game, game_fd);
	if (are_game_ok(game))
	{
		sprites_filler(game);
		return (1);
	}
	free_game(game);
	printf("Error\nsomething_not_turned_in");
	return (0);
}
