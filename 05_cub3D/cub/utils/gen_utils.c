/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:36:22 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/07 17:36:23 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

void	free_if_exists(void **var)
{
	if (*var)
		free(*var);
	*var = 0;
}

void	free_mat(void **mat)
{
	size_t	index;

	index = 0;
	if (mat)
	{
		while (mat[index])
		{
			free_if_exists(&mat[index]);
			index++;
		}
	}
}

int	check_suffix(char *str, char *suffix)
{
	int	suff_len;
	int	index;

	suff_len = ft_strlen(suffix);
	index = ft_strlen(str);
	if (index > suff_len)
	{
		while (suff_len)
		{
			if (suffix[suff_len - 1] != str[index - 1])
				return (0);
			suff_len--;
			index--;
		}
		return (1);
	}
	return (0);
}

int	check_string(char *to_check, char *checker)
{
	int	checker_len;
	int	to_check_index;

	checker_len = ft_strlen(checker);
	to_check_index = ft_strlen(to_check);
	if (checker_len != to_check_index)
		return (0);
	to_check_index = 0;
	while (to_check_index < checker_len)
	{
		if (to_check[to_check_index] != checker[to_check_index])
			return (0);
		to_check_index++;
	}
	return (1);
}
