/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:20:16 by lasablon          #+#    #+#             */
/*   Updated: 2024/05/25 16:03:57 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int searchedChar)
{
	int	i;

	i = 0;
	while (str[i] != (unsigned char)searchedChar && str[i])
		i++;
	if (str[i] == (unsigned char)searchedChar)
		return ((char *)str + i);
	return (NULL);
}
