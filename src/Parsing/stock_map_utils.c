/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:31:11 by zmogne            #+#    #+#             */
/*   Updated: 2025/01/28 19:28:53 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_l(char *line, int fd, char **temp_map, t_map_context *context)
{
	if (line)
		free(line);
	if (fd != -1)
		finish_reading_file(fd);
	if (temp_map)
	{
		*temp_map = NULL;
	}
	if (context)
		free_context_map(context);
}

void	free_context_map(t_map_context *context)
{
	if (!context || !context->temp_map)
		return ;
	while (context->idx > 0)
	{
		free(context->temp_map[--(context->idx)]);
		context->temp_map[context->idx] = NULL;
	}
}

void	free_line_map(char *line, t_map_context *context)
{
	free(line);
	free_context_map(context);
}

void	write_and_free(char *str, char *to_free)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	free(to_free);
}
