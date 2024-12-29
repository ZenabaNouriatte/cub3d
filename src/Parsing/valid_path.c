/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:41:20 by zmogne            #+#    #+#             */
/*   Updated: 2024/12/27 12:05:58 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// check si bien fini par .cub
// check si fichier existe
// check si ce n'est pas un directory

int	check_path(char *map_path, t_data *data)
{
	int	len;
	int fd;
    char buf[1];
    int ret;

	len = ft_strlen(map_path);
	if (len < 4)
		err("File name too short",data, 1);
	if (ft_strcmp(&map_path[len - 4], ".cub") != 0)
        err("Wrong file extension",data, 1);
	fd = open(map_path, O_RDONLY);
    if (fd == -1)
        err("Can't open file",data, 1);
    ret = read(fd, buf, 1);
    close(fd);
    if (ret <= 0)
        err("Empty file / Name is a directory",data, 1);
    return (0);
}
