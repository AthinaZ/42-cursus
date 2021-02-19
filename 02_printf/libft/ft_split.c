/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:11:47 by azouzoul          #+#    #+#             */
/*   Updated: 2021/01/21 19:11:23 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wcount(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (i);
}

char			**ft_split(char const *s, char c)
{
	char	**d;
	char	*start;
	size_t	l;
	size_t	i;

	if (!s || !(d = (char **)malloc((ft_wcount(s, c) + 1) * sizeof(char *))))
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			l = s - start + 1;
			if (!(d[i] = (char *)malloc(l)))
				return (0);
			ft_strlcpy(d[i++], start, l);
		}
		else
			s++;
	}
	d[i] = 0;
	return (d);
}
