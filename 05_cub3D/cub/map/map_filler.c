/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:51:50 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/07 17:51:52 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

void	copy_mat(char **dest, char **src)
{
	size_t	index_y;

	index_y = 0;
	if (!src)
		return ;
	while (src[index_y])
	{
		dest[index_y] = src[index_y];
		index_y++;
	}
}

size_t	mat_len(char **mat)
{
	size_t	index;

	index = 0;
	if (mat)
	{
		while (mat[index])
			index++;
	}
	return (index);
}

void	print_mat(char **mat)
{
	size_t	index_y;

	index_y = 0;
	while (mat[index_y])
	{
		printf("|%s|\n", mat[index_y]);
		index_y++;
	}
}

void	add_string_to_mat(char ***mat, char *str)
{
	char	**temp_mat;
	size_t	len_mat;

	len_mat = mat_len(*mat);
	temp_mat = (char **)ft_calloc(sizeof(char *), len_mat + 2);
	copy_mat(temp_mat, *mat);
	temp_mat[len_mat] = ft_strdup(str);
	if (*mat)
		free(*mat);
	*mat = temp_mat;
}

void	mat_size(t_game *game)
{
	int	y_index;
	int	len;

	y_index = 0;
	{
		game->map_size->size_x = ft_strlen(game->map[0]);
		while (game->map[y_index])
		{
			len = ft_strlen(game->map[y_index]);
			if (len > game->map_size->size_x)
				game->map_size->size_x = len;
			y_index++;
		}
		game->map_size->size_y = mat_len(game->map);
	}
}
