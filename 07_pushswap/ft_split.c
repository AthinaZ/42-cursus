/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:11:39 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/30 16:11:42 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_counter(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
		}
	}
	return (count);
}

static	int	ft_sizeword(char const *s, char c, int i)
{
	int	count;
	int	k;

	count = 0;
	k = i;
	while (s[k] != c && s[k])
	{
		count++;
		k++;
	}
	return (count);
}

static	char	**ft_cut_split(char const *s, char c, int i, char **arr)
{
	int	k;
	int	t;

	k = 0;
	t = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			arr[t] = (char *)malloc(sizeof(char) * (ft_sizeword(s, c, i)) + 1);
			if (arr[t] == NULL)
				return (NULL);
			while (s[i] && s[i] != c)
				arr[t][k++] = s[i++];
			arr[t++][k] = '\0';
			k = 0;
		}
		else
			i++;
	}
	arr[t] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	arr = (char **)malloc(sizeof(char *) * (ft_counter(s, c) + 1));
	if (s == NULL || arr == NULL)
		return (NULL);
	i = 0;
	ft_cut_split(s, c, i, arr);
	return (arr);
}
