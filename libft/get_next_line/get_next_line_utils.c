/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:47:46 by lasablon          #+#    #+#             */
/*   Updated: 2024/12/23 12:36:48 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_queue(char *queue, int start, size_t len)
{
	size_t	i;
	size_t	y;
	char	*new;

	start = start + 1;
	i = start;
	y = 0;
	if ((size_t)start > ft_strlen(queue))
		return (free_str(&queue), NULL);
	if (len >= ft_strlen(&queue[start]))
		new = malloc((ft_strlen(&queue[start]) + 1) * sizeof(char));
	else
		new = malloc((len + 1 * sizeof(char)));
	if (!new)
		return (NULL);
	while (y < len && queue[i])
		new[y++] = queue[i++];
	new[y] = '\0';
	if (*new == '\0')
	{
		free_str(&new);
		return (free_str(&queue), NULL);
	}
	free_str(&queue);
	return (new);
}

int	find_char_index(char *str, int searchedChar)
{
	int	i;

	i = 0;
	while (str[i] != (unsigned char)searchedChar && str[i])
		i++;
	if (str[i] == (unsigned char)searchedChar)
		return (i);
	return (-1);
}

void	free_str(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}
