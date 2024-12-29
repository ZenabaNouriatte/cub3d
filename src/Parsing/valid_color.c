/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:45:54 by zmogne            #+#    #+#             */
/*   Updated: 2024/12/29 21:39:43 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// verifie si F et C , verifie si pas de doublons, extrait les str

int is_color_line(const char *line, char color)
{
    return (line[0] == color && line[1] == ' ');
}

int color_info(char *line, char **f_line, char **c_line, t_data *data)
{
    int len;

    line = skip_spaces(line);
    if (is_color_line(line, 'F'))
    {
        if (*f_line != NULL)
            err ("Only one floor color needed",data, 1);
        len = ft_strlen(line);
        if (len <= 3)
            err("Line too short for parsing", data, 1);
        *f_line = ft_substr((const char*)line, 2 , len - 3);
        printf("DEBUG Floor color [%s]\n",*f_line);
        if (!*f_line)
            err ("Must be floor color",data, 1);
    }
    else if (is_color_line(line, 'C'))
    {
        if (*c_line != NULL)
            err ("Only one ceiling color needed",data, 1);
        len = ft_strlen(line);
        if (len <= 3)
            err("Line too short for parsing", data, 1);
        *c_line = ft_substr((const char*)line, 2 , len - 3);
        printf("DEBUG Ceiling color [%s]\n",*c_line);
        if (!*c_line)
            err ("Must be floor color",data, 1);
    }
    return (0);
}



