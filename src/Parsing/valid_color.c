/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:45:54 by zmogne            #+#    #+#             */
/*   Updated: 2025/01/31 16:46:21 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	color_line(char *line, char **color_line, char *error_message)
{
	int	len;

	if (*color_line != NULL)
	{
		return (ft_putstr_fd("Error\n", 2), ft_putstr_fd(error_message, 2), -1);
	}
	len = ft_strlen(line);
	if (len <= 3)
		return (ft_putstr_fd("Error\nLine too short\n", 2), -1);
	if (ft_strchr(line, '\n') != NULL)
		*color_line = ft_substr((const char *)line, 2, len - 3);
	if (ft_strchr(line, '\n') == NULL)
		*color_line = ft_substr((const char *)line, 2, len - 2);
	if (!*color_line)
		return (ft_putstr_fd("Error\nFailed to extract color line\n", 2), -1);
	return (0);
}

int	tab_to_rgb(char **tab)
{
	int		i;
	int		*nb;
	int		rgb;

	i = 0;
	nb = malloc(sizeof(int) * 3);
	if (!nb)
		return (free_tab(tab), -1);
	if (count_tab(tab) == -1)
		return (free_tab(tab), -1);
	while (i < 3)
	{
		if (is_only_spaces(tab[i]) == -1)
			return (free(nb), free_tab(tab), -1);
		nb[i] = ft_atoi(tab[i]);
		if (nb[i] > INT_MAX || nb[i] > 255 || nb[i] < 0)
			return (free(nb), free_tab(tab), -1);
		i++;
	}
	free_tab(tab);
	rgb = trgb(0, nb[0], nb[1], nb[2]);
	free(nb);
	return (rgb);
}

int	color_nbr(char *line)
{
	char	**tab;
	char	**temp_tab;
	int		result;

	if (check_commas_and_spacing(line) == -1 || check_line_char(line) == -1
		|| count_commas(line) != 2)
		return (ft_putstr_fd("Error\nWrong color config\n", 2), -1);
	temp_tab = ft_split((const char *)line, ',');
	if (!temp_tab)
	{
		ft_putstr_fd("Split failed\n", 2);
		return (-1);
	}
	tab = trim_tab_space(temp_tab);
	if (!tab)
		return (free_tab(temp_tab), -1);
	result = tab_to_rgb(tab);
	if (result == -1)
		return (ft_putstr_fd("Error\nWrong color config\n", 2), -1);
	else
		return (result);
}

int	color_info(char *line, char **f_line, char **c_line)
{
	line = skip_spaces(line);
	if (is_color_line(line, 'F'))
		return (color_line(line, c_line, "Only one floor color needed\n"));
	if (is_color_line(line, 'C'))
		return (color_line(line, f_line, "Only one ceiling color needed\n"));
	return (0);
}
