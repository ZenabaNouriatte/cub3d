/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:34:04 by zmogne            #+#    #+#             */
/*   Updated: 2024/12/29 21:09:42 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void finish_reading_file(int fd)
{
    char *line;

       if (fd < 0)
        return;
    line = get_next_line(fd);
    while (line != NULL)
    {
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}
void err (char *str,t_data *data, int flag_exit)
{
    ft_putstr_fd("Error : ", 2);
    ft_putstr_fd(str, 2);
    ft_putstr_fd("\n", 2);
    if (data->map.map_fd >= 0)
    {
        finish_reading_file(data->map.map_fd);
        data->map.map_fd = -1; // reinitialiser apres la fer;eture
    }
    if (data)
        free_data(data);
    if (data->map.map_fd != -1)
    {
        finish_reading_file(data->map.map_fd);
    }
    if (flag_exit == 1)
        exit(1);
}

void print_map(char **map) 
{
    int i;

    i = 0;
    if (!map) 
    {
        printf("Error: map is NULL\n");
        return;
    }
    while (map[i]) 
    {
        printf("%s\n", map[i]);
        i++;
    }
}

char *skip_spaces(char *str)
{
    while (*str && (*str == ' ' || *str == '\t'))
        str++;
    return str;
}

int count_commas(char *str)
{
    int count;

    count = 0;
    while (*str)
    {
        if (*str == ',')
            count++;
        str++;
    }
    return (count);
}

int check_line_char(char *line)
{
    int i;

    i = 0;
    while ( line[i])
    {
        if (!ft_isdigit(line[i]) && line[i] != ',')
            return (-1);
        i++;
    }
    return (0);
    
}

