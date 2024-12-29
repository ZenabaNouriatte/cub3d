/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:47:51 by zmogne            #+#    #+#             */
/*   Updated: 2024/12/29 19:32:22 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_t_path(char *t_path, t_data *data)
{
	int	len;
	int fd;
    char buf[1];
    int ret;

	len = ft_strlen(t_path);
	if (len < 4)
		err("Texture File name too short",data, 1);
	if (ft_strcmp(&t_path[len - 4], ".xpm") != 0)
        err("Wrong texture file extension",data, 1);
	fd = open(t_path, O_RDONLY);
    if (fd == -1)
        err("Can't open texture file",data, 1);
    ret = read(fd, buf, 1);
    close(fd);
    if (ret <= 0)
        err("Empty texture file / Name is a directory",data, 1);
    return (0);
}

void check_no(char *line, t_data *data)
{
    int len;
    
    if (ft_strncmp(line, "NO ", 3) == 0) 
    {
        if (data->map.textures.north  != NULL)
            err("More than one NO value",data, 1);
        len = ft_strlen(line);
        data->map.textures.north  = ft_substr((const char*)line, 3 , len - 4);
        if (!data->map.textures.north )
            return ;
        printf("DEBUG Texture North: [%s]\n", data->map.textures.north );
        check_t_path(data->map.textures.north, data);
    }
}

void check_so(char *line, t_data *data)
{
    int len;
    
    if (ft_strncmp(line, "SO ", 3) == 0) 
    {
        if (data->map.textures.south != NULL)
            err("More than one SO value",data, 1);
        len = ft_strlen(line);
        data->map.textures.south = ft_substr((const char*)line, 3 , len - 4);
        if (!data->map.textures.south)
            return ;
        printf("DEBUG Texture South: [%s]\n", data->map.textures.south);
        check_t_path(data->map.textures.south, data);
    }
}
void check_w(char *line, t_data *data)
{
    int len;
    
    if (ft_strncmp(line, "WE ", 3) == 0) 
    {
        if (data->map.textures.west != NULL)
            err("More than one WE value",data, 1);
        len = ft_strlen(line);
        data->map.textures.west = ft_substr((const char*)line, 3 , len - 4);
        if (!data->map.textures.west)
            return ;
        printf("DEBUG Texture WEST: [%s]\n", data->map.textures.west);
        check_t_path(data->map.textures.west, data);
    }
}

void check_ea(char *line, t_data *data)
{
    int len;
    
    if (ft_strncmp(line, "EA ", 3) == 0) 
    {
        if (data->map.textures.east != NULL)
            err("More than one EA value", data,1);
        len = ft_strlen(line);
        data->map.textures.east = ft_substr((const char*)line, 3 , len - 4);
        if (!data->map.textures.east)
            return ;
        printf("DEBUG Texture EAST: [%s]\n", data->map.textures.east);
        check_t_path(data->map.textures.east, data);
    }
}

// stock les infos , check les doublons et si le path est ok
void texture_info(char *line, t_data *data)
{
    line = skip_spaces(line);
    check_no(line, data);
    check_so(line, data);
    check_w(line, data);
    check_ea(line, data);
    
}

