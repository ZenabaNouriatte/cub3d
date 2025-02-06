/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:56:08 by lasablon          #+#    #+#             */
/*   Updated: 2025/01/31 16:40:52 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*queue;
	char		*buff;
	char		*line;
	int			bytes_read;
	int			eol_index;

	line = NULL;
	bytes_read = 0;
	if ((fd >= 0 || BUFFER_SIZE <= 0))
	{
		while (!line)
		{
			buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
			if (!read_fd(fd, &bytes_read, buff, &queue))
				return (NULL);
			queue = add_buffer_to_queue(queue, buff, bytes_read);
			if (!queue)
				return (NULL);
			line = check_queue(&eol_index, &queue, line, bytes_read);
			free_str(&buff);
		}
	}
	return (line);
}

int	read_fd(int fd, int *bytes_read, char *buff, char **queue)
{
	if (!buff)
		return (0);
	*bytes_read = read(fd, buff, BUFFER_SIZE);
	if (*bytes_read != -1)
		buff[*bytes_read] = '\0';
	if (*bytes_read < 0 || (*bytes_read == 0 && *buff == '\0' && (!*queue
				|| **queue == '\0')))
	{
		free_str(queue);
		free_str(&buff);
		return (0);
	}
	return (1);
}

char	*check_queue(int *eol_index, char **queue, char *line, int bytes_read)
{
	*eol_index = find_char_index(*queue, '\n');
	if (*eol_index != -1 || (*eol_index == -1 && bytes_read == 0))
	{
		if (*eol_index == -1)
			*eol_index = ft_strlen(*queue);
		line = ft_fill_line(*queue, eol_index, bytes_read);
		*queue = update_queue(*queue, *eol_index, ft_strlen(*queue));
		return (line);
	}
	return (NULL);
}

char	*add_buffer_to_queue(char *queue, char *buff, int bytes_read)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	if (bytes_read == 0)
		return (queue);
	if (buff == NULL)
		return (NULL);
	if (queue == NULL)
		return (ft_strdup(buff));
	new = malloc((ft_strlen(queue) + bytes_read + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (queue[i])
	{
		new[i] = queue[i];
		i++;
	}
	while (buff[j])
		new[i++] = buff[j++];
	new[i] = '\0';
	free_str(&queue);
	return (new);
}

char	*ft_fill_line(char *queue, int *eol_index, int bytes_read)
{
	char	*line;
	int		i;

	if (*eol_index != -1 || (*eol_index == -1 && bytes_read == 0))
		line = malloc((ft_strlen(queue) + 1) * sizeof(char));
	else
		line = malloc((ft_strlen(queue) + 2) * sizeof(char));
	if (!line || !queue)
		return (NULL);
	i = 0;
	while (queue[i] && i < *eol_index)
	{
		line[i] = queue[i];
		i++;
	}
	if (queue[i] == '\n')
	{
		line[i] = queue[i];
		line[i + 1] = '\0';
	}
	else
		line[i] = '\0';
	return (line);
}
