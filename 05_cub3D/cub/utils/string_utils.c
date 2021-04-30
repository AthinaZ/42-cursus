/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:36:34 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/07 17:36:36 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

int	ft_numlen(char **str)
{
	int	index;

	index = 0;
	while (ft_isdigit(**str))
	{
		*str += 1;
		index++;
	}
	return (index);
}

void	ft_jump_spaces(char **str)
{
	while (*str && is_in_cset(**str, " \t\v\f\r"))
		*str += 1;
}

char	*ft_strjoin_new_line(char const *s1, char const *s2)
{
	char	*res;

	if (!s1)
	{
		if (s2)
			return ((char *)(s2));
		else
			return (0);
	}
	res = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1 + 1, sizeof(char));
	if (!res)
		return (0);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	res[ft_strlen(s1)] = '\n';
	ft_strlcpy(&res[ft_strlen(res)], s2, ft_strlen(s2) + 1);
	return (res);
}

void	change_char_in_s(char *str, char dest, char substitute)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == dest)
			str[index] = substitute;
		index++;
	}
}

int	is_in_cset(char c, char *c_set)
{
	while (*c_set)
	{
		if (*c_set == c)
			return (1);
		c_set++;
	}
	return (0);
}
