/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_color_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:37:53 by zmogne            #+#    #+#             */
/*   Updated: 2025/01/31 15:09:06 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_color_line(const char *line, char color)
{
	return (line[0] == color && (line[1] == ' ' || line[1] == '\t'));
}

int	count_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_strlen(tab[i]) > 3)
			return (-1);
		i++;
	}
	if (i != 3)
		return (-1);
	return (i);
}

int	is_only_spaces(const char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (-1);
}

static int	check_between_commas(const char *line, int start, int end)
{
	int		i;
	int		has_digit;

	has_digit = 0;
	i = start;
	while (i < end && (line[i] == ' ' || line[i] == '\t'))
		i++;
	while (i < end && ft_isdigit(line[i]))
	{
		has_digit = 1;
		i++;
	}
	while (i < end && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (has_digit && i == end);
}

int	check_commas_and_spacing(const char *line)
{
	int		i;
	int		start;
	int		count;

	i = 0;
	count = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	start = i;
	while (line[i] && count < 3)
	{
		while (line[i] && line[i] != ',' && line[i] != '\0')
			i++;
		if (!check_between_commas(line, start, i))
			return (-1);
		if (line[i] == ',')
			i++;
		start = i;
		count++;
	}
	if (count == 3)
		return (0);
	else
		return (-1);
}
