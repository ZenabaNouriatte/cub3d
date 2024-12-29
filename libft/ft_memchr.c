/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:32:28 by lasablon          #+#    #+#             */
/*   Updated: 2024/05/25 15:51:35 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (NULL);
	while (i < size)
	{
		if (((char *)memoryBlock)[i] == (char)searchedChar)
			return (((char *)memoryBlock) + i);
		i++;
	}
	return (NULL);
}
