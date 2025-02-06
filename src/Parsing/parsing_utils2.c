/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:34:04 by zmogne            #+#    #+#             */
/*   Updated: 2025/01/28 01:37:27 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	finish_reading_file(int fd)
{
	char	*line;

	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

char	*trim_spaces(char *str)
{
	char	*start;
	char	*end;
	char	*result;

	start = str;
	while (*start && (*start == ' ' || *start == '\t'))
		start++;
	end = start + ft_strlen(start) - 1;
	while (end > start && (*end == ' ' || *end == '\t'))
		end--;
	result = ft_substr(start, 0, end - start + 1);
	return (result);
}

int	count_commas(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == ',')
			count++;
		str++;
	}
	return (count);
}

int	check_line_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ','
			&& line[i] != ' ' && line[i] != '\t')
			return (-1);
		i++;
	}
	return (0);
}

char	**trim_tab_space(char **temp_tab)
{
	char	**tab;
	int		i;
	int		j;

	tab = malloc(sizeof(char *) * 4);
	if (!tab)
		return (free_tab(temp_tab), NULL);
	j = 0;
	i = 0;
	while (temp_tab[j])
	{
		tab[i] = trim_spaces(temp_tab[j]);
		if (!tab[i])
			return (free_tab(temp_tab), NULL);
		i++;
		j++;
	}
	tab[i] = NULL;
	free_tab(temp_tab);
	return (tab);
}
