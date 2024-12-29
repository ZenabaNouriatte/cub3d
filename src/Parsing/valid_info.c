/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:55:47 by zmogne            #+#    #+#             */
/*   Updated: 2024/12/29 21:40:21 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*Premiere lecture du fichier pour rechercher , verifier et stocker les infos hors map 
+ parsing nom du fichier */

static void search_info(char *line,char **f_line, char **c_line, t_data *data)
{
    texture_info(line, data);
    color_info(line,f_line, c_line, data);
}

int *color_nbr(char *line, t_data *data)
{
    char    **tab;
    int    *nb;

    if (count_commas(line) > 2)
        err("Wrong color config",data, 1);
    nb = malloc(sizeof(int) * 3);
    if (!nb) 
    {
        err("Memory allocation failed",NULL, 0);
        return NULL;
    }
    tab = ft_split((const char*)line, ',');
    if (!tab) 
    {
        err("ft_split failed",NULL, 0);
        free(nb);
        return NULL;
    }
    nb[0] = ft_atoi(tab[0]);
    nb[1] = ft_atoi(tab[1]);
    nb[2] = ft_atoi(tab[2]);
    free_tab(tab);
    return (nb);
}

int valid_rgb_number(int *nb, t_data *data)
{
    int i;

    i = 0;
    while (nb[i] && i < 3)
    {
        if (nb[i] > INT_MAX || nb[i] > 255 || nb[i] < 0)
        {
            err("Invalid RGB value",data,0);
            free(nb);
            free_data(data);
            exit(1);
        }
        i++;
    }
    //printf("Debug Nb[0]%d\nDebug Nb[1]%d\nDebug Nb[2]%d\n", nb[0], nb[1], nb[2]);
    return trgb(0, nb[0], nb[1], nb[2]);  
}
static void valid_info (t_data *data, char *f_line, char *c_line) // a reduire
 {
    int *nb_f;
    int *nb_c;

    if (data->map.textures.west == NULL)
        err("No W texture",data, 1);
    if (data->map.textures.north == NULL)
        err("No N texture",data, 1);
    if (data->map.textures.east == NULL)
        err("No E texture",data, 1);
    if (data->map.textures.south == NULL)
        err("No S texture",data, 1);
    if (f_line == NULL)
        err("No Floor color",data, 1);
    if (c_line == NULL)
        err("No No ceiling color",data, 1);
    nb_f = color_nbr(f_line, data);
    nb_c = color_nbr(c_line, data);
    data->map.textures.ceiling = valid_rgb_number(nb_c, data);
    data->map.textures.floor = valid_rgb_number(nb_f, data);
    free(nb_c);
    free(nb_f);
    printf("C COLOR [%d]\n", data->map.textures.ceiling);
    printf("F COLOR [%d]\n", data->map.textures.floor);     
}

int read_map(char *map_path, t_data *data)
{
	char	*line;
    char    *f_line;
    char    *c_line;

    c_line = NULL;
    f_line = NULL;
    check_path(map_path, data);
	data->map.map_fd = open(map_path, O_RDONLY);
	while (1)
	{
		line = get_next_line(data->map.map_fd);
		if (line == NULL)
			break ;
        search_info(line,&f_line,&c_line, data);
		free(line);
	}
	close(data->map.map_fd);
    data->map.map_fd = -1;
    valid_info(data,f_line,c_line);
	free(f_line);
    free(c_line);
    return (0);
}
 

