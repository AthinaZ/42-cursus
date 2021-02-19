/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:37:12 by azouzoul          #+#    #+#             */
/*   Updated: 2021/02/01 12:37:22 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*after_newline(char *db)
{
	char	*leftover;
	int		index_leftover;
	int		index_line;

	index_leftover = 0;
	index_line = 0;
	if (!db)
		return (0);
	while (db[index_line] && db[index_line] != '\n')
		index_line++;
	if (!db[index_line])
	{
		free(db);
		return (0);
	}
	if (!(leftover = malloc(sizeof(char) * ((ft_strlen(db) - index_line) + 1))))
		return (0);
	index_line++;
	while (db[index_line])
		leftover[index_leftover++] = db[index_line++];
	leftover[index_leftover] = '\0';
	free(db);
	return (leftover);
}

char	*buff_read_line(char *db)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!db)
		return (0);
	while (db[i] && db[i] != '\n')
		i++;
	if (!(line = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (db[i] && db[i] != '\n')
	{
		line[i] = db[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*db[MAX_FD];
	int			res;

	res = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!line_exists(db[fd]) && res != 0)
	{
		if ((res = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[res] = '\0';
		db[fd] = strjoin(db[fd], buffer);
	}
	free(buffer);
	*line = buff_read_line(db[fd]);
	db[fd] = after_newline(db[fd]);
	if (res == 0)
		return (0);
	return (1);
}
