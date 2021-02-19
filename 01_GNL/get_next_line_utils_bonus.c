/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:10:17 by azouzoul          #+#    #+#             */
/*   Updated: 2021/01/29 19:10:53 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		line_exists(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < len)
	{
		if (dst < src)
			((char *)dst)[i] = ((char *)src)[i];
		else
			((char *)dst)[len - i - 1] = ((char *)src)[len - i - 1];
		i++;
	}
	return (dst);
}

char	*strjoin(char const *s1, char const *s2)
{
	char	*joinstr;
	size_t	s1_len;
	size_t	s2_len;
	size_t	tot_len;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	tot_len = s1_len + s2_len + 1;
	if (!(joinstr = malloc(sizeof(char) * tot_len)))
		return (0);
	ft_memmove(joinstr, s1, s1_len);
	ft_memmove(joinstr + s1_len, s2, s2_len);
	joinstr[tot_len - 1] = '\0';
	free((char *)s1);
	return (joinstr);
}
