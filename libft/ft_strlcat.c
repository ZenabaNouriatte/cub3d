/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:20:59 by lasablon          #+#    #+#             */
/*   Updated: 2024/05/28 12:45:49 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	y;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	y = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size > 0)
	{
		while (dst[i])
			i++;
		while (i < size - 1 && src[y])
		{
			dst[i] = src[y];
			i++;
			y++;
		}
	}
	if (size <= dst_len)
		return (size + src_len);
	if (size > 0 && size < __INT32_MAX__)
		dst[i] = '\0';
	return (dst_len + src_len);
}
