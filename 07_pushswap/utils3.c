/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:13:40 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/30 16:13:41 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*s3;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen2(s1) + ft_strlen2(s2);
	s3 = malloc(len + 1);
	if (!(s3))
		return (NULL);
	ft_strlcpy2(s3, s1, ft_strlen2(s1) + 1);
	ft_strlcat(s3, (char *)s2, len + 1);
	free(s1);
	return (s3);
}

int	ft_strlen2(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy2(char *dst, char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (!dst)
		return (0);
	while (src[len])
		len++;
	if (dstsize != 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*(dst + i) && i < dstsize)
		++i;
	while (*src && i + 1 < dstsize)
	{
		*(dst + i) = *src;
		++src;
		++i;
	}
	if (i < dstsize)
		*(dst + i) = 0;
	while (*src++)
		++i;
	return (i);
}

void	ft_printalo2(t_list *tmp, t_list *tmp1)
{
	int	len;

	while (tmp || tmp1)
	{
		if (tmp)
		{
			len = ft_numlen(tmp->content);
			ft_printzero(tmp);
			tmp = tmp->next;
		}
		else
			write(1, "                 ", 17);
		while (len++ < 18)
			write(1, " ", 1);
		if (tmp1)
		{
			if (tmp1->content == 0)
				write(1, "0", 1);
			else
				write(1, ft_itoa(tmp1->content), ft_numlen(tmp1->content));
			tmp1 = tmp1->next;
		}
		write(1, "\n", 1);
	}
}
