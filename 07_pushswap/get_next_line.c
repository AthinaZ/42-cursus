/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:11:48 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/30 16:11:51 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1 || !s2 || !str)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while ((*s != (unsigned char)c) && (*s != '\0'))
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_get_line_read(int fd, char **remainder)
{
	char	buf[BUFFER_SIZE + 1];
	int		currently_read;
	char	*mem_to_free;

	if (*remainder == NULL)
		*remainder = ft_strdup("");
	while (!(ft_strchr(*remainder, '\n')))
	{
		currently_read = read(fd, buf, BUFFER_SIZE);
		if (currently_read < 0)
			return (0);
		buf[currently_read] = '\0';
		mem_to_free = *remainder;
		*remainder = ft_strjoin(*remainder, buf);
		free(mem_to_free);
		if (currently_read == 0)
			break ;
	}
	return (*remainder);
}

int	ft_get_next_line(int fd, char **line)
{
	static char		*remainder[256];
	char			*ptr_n;

	if (fd < 0 || fd > 256 || BUFFER_SIZE < 1)
		return (-1);
	remainder[fd] = ft_get_line_read(fd, &remainder[fd]);
	if (!line || !remainder[fd])
		return (-1);
	ptr_n = ft_strchr(remainder[fd], '\n');
	if (!ptr_n)
	{
		*line = remainder[fd];
		remainder[fd] = NULL;
		return (0);
	}
	else
	{
		*ptr_n = '\0';
		*line = ft_strdup(remainder[fd]);
		ft_strcpy(remainder[fd], ++ptr_n);
		return (1);
	}
}
