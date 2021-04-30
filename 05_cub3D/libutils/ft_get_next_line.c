/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:44:14 by azouzoul          #+#    #+#             */
/*   Updated: 2021/04/07 17:44:15 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

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
